local Response=require("Response");
local Stype=require("Stype");
local Cmd=require("Cmd");
local game_mgr=require("logic_server/game_mgr")


local logic_service_handlers={}

logic_service_handlers[Cmd.eLoginLogicReq]=game_mgr.login_logic_server;



--{stype,ctype,utag,[{message} or jsonStr]}
function on_logic_recv_cmd( s,msg )
    if logic_service_handlers[msg[2]]  then
        logic_service_handlers[msg[2]](s,msg);
    end
end


function on_logic_session_disconnect( s,stype )

end 

local logic_service={
    on_session_recv_cmd=on_logic_recv_cmd,
    on_session_disconnect=on_logic_session_disconnect,
};



return logic_service;