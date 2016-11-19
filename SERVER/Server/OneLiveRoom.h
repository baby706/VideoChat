#ifndef ONELIVEROOM_H
#define ONELIVEROOM_H

#include <QTcpSocket>
#include <vector>

using namespace std;

typedef struct{
    QTcpSocket *userSocket;         //用户的套接字
    QString userAccount;            //用户的账号
}visitor_t;

class OneLiveRoom
{
public:
    OneLiveRoom();
    void addVisitor(QTcpSocket* socket,QString account);    //添加游客
    void removeVisitor(QString account); //删除游客
    vector<visitor_t*> getAllUser(); //获取所有用户信息
    void setHostAccount(QString&);  //设置房间主播账号
    QString getHostAccount(){return hostAccount;}         //获取主播账号
    void setUdpAddress(QString);    //设置房间udp地址
    QString getUdpAddress(){ return udpAddress;}  //获取房间udp地址
private:
    vector<visitor_t*> roomInfo;    //房间所有用户信息
    QString hostAccount;            //主播账号
    QString udpAddress;             //udp组播地址
};

#endif // ONELIVEROOM_H
