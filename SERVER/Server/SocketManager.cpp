#include "SocketManager.h"

SocketManager* SocketManager::instance = new SocketManager();

SocketManager::SocketManager()
{

}

SocketManager* SocketManager::getInstance()
{
    return instance;
}


void SocketManager::insertSocketInfo(SocketInfo *si)
{
    clients.push_back(si);
}

vector<SocketInfo*> SocketManager::getAllClinets()const
{
    return clients;
}

void SocketManager::addOnlineUser(QTcpSocket* socket)       //添加在线用户套接字
{
    onlineUser.push_back(socket);
}

vector <QTcpSocket*> SocketManager::getAllOnlineUser()const //获取所有在线用户套接字
{
    return onlineUser;
}

//移除客户端套接字
void SocketManager::removeSocketInfo(QTcpSocket* tcpSocket)
{
    vector <SocketInfo*>::iterator it_clients;
    for(it_clients = clients.begin();it_clients != clients.end();it_clients++)
    {
        if(((*it_clients)->getSocket()) == tcpSocket)
        {
            clients.erase(it_clients);
            return;
        }
    }
}

//移除在线用户套接字
void SocketManager::removeOnlineUser(QTcpSocket* tcpSocket)
{
    vector <QTcpSocket*>::iterator it_onlineUser;
    for(it_onlineUser = onlineUser.begin();it_onlineUser != onlineUser.end();it_onlineUser++)
    {
        if((*it_onlineUser) == tcpSocket)
        {
            onlineUser.erase(it_onlineUser);
            return;
        }
    }
}

void SocketManager::addOnlineAccount(QString account)
{
    onlineAccount.push_back(account);
}

void SocketManager::removeOnlineAccount(QString account)
{
     vector <QString>::iterator it_onlineAccount;
     for(it_onlineAccount = onlineAccount.begin();it_onlineAccount != onlineAccount.end();it_onlineAccount++)
     {
         if((*it_onlineAccount) == account)
         {
             onlineAccount.erase(it_onlineAccount);
             return;
         }
     }
}
bool SocketManager::selectOnlineAccount(QString account)
{
    vector <QString>::iterator it_onlineAccount;
    for(it_onlineAccount = onlineAccount.begin();it_onlineAccount != onlineAccount.end();it_onlineAccount++)
    {
        if((*it_onlineAccount) == account)
        {
            return true;
        }
    }
    return false;
}
