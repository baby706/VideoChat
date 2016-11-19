#include "OneLiveRoom.h"
#include <cstdlib>
#include <QDebug>
#include <algorithm>

OneLiveRoom::OneLiveRoom()
{

}

//添加游客
void OneLiveRoom::addVisitor(QTcpSocket* socket,QString account)
{
    visitor_t *visitor = (visitor_t*)calloc(1,sizeof(visitor_t));
    //visitor->userAccount = account;
    memcpy(&(visitor->userAccount),&account,sizeof(account));  //???只能使用memcpy进行赋值
    visitor->userSocket = socket;

    roomInfo.push_back(visitor);
}

//删除游客
void OneLiveRoom::removeVisitor(QString account)
{
    vector<visitor_t*>::iterator it_roomInfo;
    for(it_roomInfo = roomInfo.begin();it_roomInfo != roomInfo.end();it_roomInfo++)
    {
        if((*it_roomInfo)->userAccount == account)
        {
            roomInfo.erase(it_roomInfo);
            return;
        }
    }
}

//设置房间主播账号
void OneLiveRoom::setHostAccount(QString& host)
{
    hostAccount = host;
}

//获取所有用户信息
vector<visitor_t*> OneLiveRoom::getAllUser()
{
    return roomInfo;
}

//设置房间udp地址
void OneLiveRoom::setUdpAddress(QString add)
{
   udpAddress =  add;
}
