local Response=require("Response");
local Stype=require("Stype");
local Cmd=require("Cmd");
local mysql_game=require("database/mysql_game");
local redis_game=require("database/redis_game");
local redis_center=require("database/redis_center");
local State=require("logic_server/State")
local Zone=require("logic_server/Zone");

local player={};


function player:new( instant )
    if not instant then
        instant={};
    end
    setmetatable(instant, {__index=self});
    return instant;
end


function player:init( uid,s,ret_handler )
    self.session=s;
    self.uid=uid;
    self.zid=-1;--表明玩家所在空间 -1：不在任何游戏场中
    self.matchid=-1;--玩家所在的比赛房间的id
    self.seatid=-1;
    self.side=-1--玩家所在的阵营 0(左边)1(右边)
    self.heroid=-1;--玩家英雄编号
    self.state=State.InView;--玩家当前处于旁观状态
    self.is_robot=false;--对象是否为机器人

    --从数据库中读取玩家基本信息；
    mysql_game.get_ugame_info(uid,
    function ( err,ugame_info )
        if err then
            if ret_handler then
                ret_handler(Response.SystemErr);
            end
            return;
        end

        self.ugame_info=ugame_info;

        redis_center.get_uinfo_inredis(uid,
        function ( err,uinfo )
            if err then
                if ret_handler then
                    ret_handler(Response.SystemErr);
                end
                return;
            end

            self.uinfo=uinfo;
            if ret_handler then
                ret_handler(Response.OK);
            end
        end)
    end)

    --。。其他信息后面在读
end

function player:get_user_arrived( )
    local body={
        unick=self.uinfo.unick,
        uface=self.uinfo.uface,
        usex=self.uinfo.usex,
        seatid=self.seatid,
        side=self.side,
    }
    return body;
end

function player:set_session(s)
    self.session=s;
end

function player:send_cmd( stype,ctype,body )
    if not self.session or self.is_robot then
        return;
    end

    local msg={stype,ctype,self.uid,body};
    Session.send_msg(self.session,msg);

end

return player 