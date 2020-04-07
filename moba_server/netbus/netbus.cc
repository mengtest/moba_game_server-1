#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <string>
using namespace std;

#include "uv.h"
#include "session.h"
#include "session_uv.h"

#include "netbus.h"
#include "ws_protocol.h"
#include "tp_protocol.h"
#include "proto_man.h"

extern "C"
{
	static void	 on_recv_client_cmd(uv_session* s, unsigned char* body, int len)
	{
		printf("get client command!\n");
			//����
		struct cmd_msg* msg = NULL;
		if (proto_man::decode_cmd_msg(body, len, &msg)) {
			unsigned char* encode_pkg = NULL;
			int encode_len = 0;
			encode_pkg = proto_man::encode_msg_to_raw(msg, &encode_len);
			if (encode_pkg) {
				s->send_data(encode_pkg, encode_len);
				proto_man::msg_raw_free(encode_pkg);
			}
			proto_man::cmd_msg_free(msg);
		}
	}

	static void on_recv_tcp_data(uv_session* s)
	{
		//�ж�ʹ�ó������Ƕ̰�
		unsigned char* pkg_data = (unsigned char*)((s->long_pkg != NULL) ? s->long_pkg : s->recv_buf);
		while (s->recved > 0)
		{
			int pkg_size = 0;
			int head_size = 0;

			//pkg_size-head_size=body_size;
			if (!tp_protocol::read_header(pkg_data, s->recved, &pkg_size, &head_size))
			{
				break;
			}
			if (s->recved < pkg_size)//���ݰ���δ����
			{
				break;
			}
			//�������ݰ�
			//pkg_data�ĵ�ַ+head_size��ƫ��=���ݵ�λ��
			unsigned char* raw_data = pkg_data + head_size;
			//�յ�һ�������������
			on_recv_client_cmd(s, raw_data, pkg_size - head_size);
			if (s->recved > pkg_size)
			{//ɾ�����Ѵ���������ݣ���δ��������ǰ��
				memmove(pkg_data, pkg_data + pkg_size, s->recved - pkg_size);
			}
			s->recved -= pkg_size;
			if (s->recved == 0 && s->long_pkg != NULL)
			{
				//�����곤����Ҫ�ͷ�
				free(s->long_pkg);
				s->long_pkg = NULL;
				s->long_pkg_size = 0;
			}
		}
	}


	static void on_recv_ws_data(uv_session* s)
	{
		//�ж�ʹ�ó������Ƕ̰�
		unsigned char* pkg_data = (unsigned char*)((s->long_pkg != NULL) ? s->long_pkg : s->recv_buf);
		while (s->recved > 0)
		{
			int pkg_size = 0;
			int head_size = 0;

			if (pkg_data[0] == 0x88) { // closeЭ��
				s->close();
				break;
			}
			//pkg_size-head_size=body_size;
			if (!ws_protocol::read_ws_header(pkg_data, s->recved, &pkg_size, &head_size))
			{
				break;
			}
			if (s->recved < pkg_size)//���ݰ���δ����
			{
				break;
			}
			//�������ݰ�
			//pkg_data�ĵ�ַ+head_size��ƫ��=���ݵ�λ��
			unsigned char* raw_data = pkg_data + head_size;
			unsigned char* mask = raw_data - 4;
			ws_protocol::parser_ws_recv_data(raw_data, mask, pkg_size - head_size);
			//�յ�һ�������������
			on_recv_client_cmd(s, raw_data, pkg_size - head_size);
			if (s->recved > pkg_size)
			{//ɾ�����Ѵ���������ݣ���δ��������ǰ��
				memmove(pkg_data, pkg_data + pkg_size, s->recved - pkg_size);
			}
			s->recved -= pkg_size;
			if (s->recved == 0 && s->long_pkg != NULL)
			{
				//�����곤����Ҫ�ͷ�
				free(s->long_pkg);
				s->long_pkg = NULL;
				s->long_pkg_size = 0;
			}
		}
	}


	static void uv_alloc_buf(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf)
	{
		uv_session* s = (uv_session*)handle->data;

		if (s->recved < RECV_LEN)
		{
			*buf = uv_buf_init(s->recv_buf + s->recved, RECV_LEN - s->recved);
		}
		else
		{
			//�����˶̰��Ŀռ䣬����δ�����������ݰ�
			if (s->long_pkg == NULL)
			{
				//websocket>RECV_LEN��package
				if (s->socket_type == WS_SOCKET && s->is_ws_shake)
				{
					int pkg_size;
					int head_size;
					//������ͷ����ȡ����
					ws_protocol::read_ws_header((unsigned char*)s->recv_buf, s->recved, &pkg_size, &head_size);
					s->long_pkg_size = pkg_size;
					s->long_pkg = (char*)malloc(pkg_size);
					memcpy(s->long_pkg, s->recv_buf, s->recved);
				}
				else
				{//tcp>RECV_LEN��package

				}
			}
			*buf = uv_buf_init(s->long_pkg + s->recved, s->long_pkg_size - s->recved);
		}
	}

	static void on_close(uv_handle_t* handle)
	{
		uv_session* s = (uv_session*)handle->data;
		uv_session::destory(s);
	}

	static void on_shutdown(uv_shutdown_t* req, int status)
	{
		uv_close((uv_handle_t*)req->handle, on_close);
	}

	static void after_write(uv_write_t* req, int status)
	{
		if (status == 0)
		{
			printf("write success!\n");
		}
		uv_buf_t* w_buf = (uv_buf_t*)req->data;
		if (w_buf != NULL)
		{
			free(w_buf);
		}
		free(req);
	}

	//��ɶ�����󣬻���øú���
	//stream: �����¼��ľ��-->uv_tcp_t
	//nread�����������ݵ��ֽڴ�С
	//buf:���е����ݶ�������buf��
	static void after_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf)
	{
		uv_session* s = (uv_session*)stream->data;
		//���ӶϿ�
		if (nread < 0)
		{
			//uv_shutdown_t* req = &s->shudown;
			//memset(req, 0, sizeof(uv_shutdown_t));
			//uv_shutdown(req, stream, on_shutdown);
			s->close();
			return;
		}

		s->recved += nread;
		if (s->socket_type == WS_SOCKET)//websocket
		{
			if (s->is_ws_shake == 0)
			{
				//���ֳɹ�
				if (ws_protocol::ws_shake_hand((session*)s, s->recv_buf, s->recved))
				{
					s->is_ws_shake = 1;
					s->recved = 0;
				}
			}
			else//web socket�շ�����
			{
				on_recv_ws_data(s);
			}
		}
		else//tcp_socket
		{
			on_recv_tcp_data(s);
		}

		//buf->base[nread] = '\0';
		//printf("recv  %d\n", nread);
		//printf("%s\n", buf->base);

		////���� ��������
		//s->send_data((unsigned char *)buf->base, nread);
		//s->recved = 0;
	}

	static void uv_connection(uv_stream_t* server, int status)//�����¼��Ļص�����
	{
		uv_session* s = uv_session::create();

		uv_tcp_t* client = &s->tcp_handler;
		memset(client, 0, sizeof(uv_tcp_t));
		uv_tcp_init(uv_default_loop(), client);
		client->data = (void*)s;

		uv_accept(server, (uv_stream_t*)client);
		struct sockaddr_in addr;
		int len = sizeof(addr);
		uv_tcp_getpeername(client, (sockaddr*)& addr, &len);//��ȡclient�˵�ip��ַ���˿���Ϣ
		uv_ip4_name(&addr, (char*)s->c_address, 64);
		s->c_port = ntohs(addr.sin_port);
		s->socket_type = (int)server->data;

		printf("new client coming  %s : %d\n", s->c_address, s->c_port);
		uv_read_start((uv_stream_t*)client, uv_alloc_buf, after_read);
	}

}

static netbus g_netbus;
netbus* netbus::instance()
{
	return &g_netbus;
}

void netbus::start_tcp_server(int port)
{
	uv_tcp_t* listen = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
	memset(listen, 0, sizeof(uv_tcp_t));

	uv_tcp_init(uv_default_loop(), listen);

	struct sockaddr_in addr;
	uv_ip4_addr("0.0.0.0", port, &addr);

	int ret = uv_tcp_bind(listen, (const sockaddr*)& addr, 0);
	if (ret != 0)
	{
		printf("bind error\n");
		free(listen);
		return;
	}

	uv_listen((uv_stream_t*)listen, SOMAXCONN, uv_connection);
	listen->data = (void*)TCP_SOCKET;
}

void netbus::start_ws_server(int port)
{
	uv_tcp_t* listen = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
	memset(listen, 0, sizeof(uv_tcp_t));

	uv_tcp_init(uv_default_loop(), listen);

	struct sockaddr_in addr;
	uv_ip4_addr("0.0.0.0", port, &addr);

	int ret = uv_tcp_bind(listen, (const sockaddr*)& addr, 0);
	if (ret != 0)
	{
		printf("bind error\n");
		free(listen);
		return;
	}

	uv_listen((uv_stream_t*)listen, SOMAXCONN, uv_connection);
	listen->data = (void*)WS_SOCKET;

}

void netbus::run()
{
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

void netbus::init()
{
	init_session_allocer();
}