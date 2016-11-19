#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <vector>
#include <QTcpSocket>
#include "SocketInfo.h"

/*用来管理所有客户端的套接字*/

using namespace std;

class SocketManager
{
public:
    static SocketManager* getInstance();
    void insertSocketInfo(SocketInfo* si);        //添加新的套接字
    void addOnlineUser(QTcpSocket* socket);           //添加在线用户套接字
    void removeSocketInfo(QTcpSocket* tcpScoket);  //移除客户端套接字
    void removeOnlineUser(QTcpSocket* tcpSocket);  //移除在线用户套接字
    void addOnlineAccount(QString account);
    void removeOnlineAccount(QString account);
    vector <SocketInfo*> getAllClinets()const;    //获取所有客户端套接字
    vector <QTcpSocket*> getAllOnlineUser()const; //获取所有在线用户套接字
    vector <QString> getAllAccount(){return onlineAccount;}
    bool selectOnlineAccount(QString);
    //int onlineUserNum;
private:
    vector <SocketInfo*> clients;                   //所有在线客户端套接字存放
    vector <QTcpSocket*> onlineUser;                //所有在线用户套接字存放（登录后）
    vector <QString> onlineAccount;                 //所有在线用户的账号
    static SocketManager* instance;
    SocketManager();
};

#endif // SOCKETMANAGER_H
