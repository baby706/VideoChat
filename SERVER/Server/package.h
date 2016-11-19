#ifndef PACKAGE_H
#define PACKAGE_H
#include <QMetaType>

enum dataType{
    REGISER_CNKI = 1,           //查重

    REGISTER_APP,       //注册
    REGISTER_FAIL,
    REGISTER_SUCCESS,

    LOGIN_APP,         //登录
    LOGIN_FAIL,
    LOGIN_SUCCESS,

    LIVE_START,          //开启直播
    LIVE_ALREADY,         //直播间已存在
    LIVE_SUCCESS,         //创建直播房间成功

    REFRESH_ROOMLIST,      //刷新房间列表
    JOIN_ROOM,             //加入房间
    JOIN_ROOM_SUCCESS,      //加入房间成功

    SEND_MESSAGE,           //发送消息
    RECEIVE_MESSAGE,         //接收消息
    VISITOR_QUIT,            //游客退出
    HOST_QUIT,               //主播退出
    NOTICE_HOSTQUIT,          //主播退出通知
    ROOM_CLOSE               //房间关闭通知
};
typedef struct package{
    //string  QString map set
    dataType    type;
    char        account[20];
    char        passwd[20];
    char        chatInfo[1024];

}pack_t;

Q_DECLARE_METATYPE(pack_t)  //这个宏具体的用法参考帮助文档

#endif // PACKAGE_H
