#include "SocketInfo.h"
#include "SocketManager.h"
#include <QString>
#include "User.h"
#include "UserHandle.h"
#include <string.h>
#include "LiveRoomList.h"
#include "OneLiveRoom.h"
#include <QByteArray>


SocketInfo::SocketInfo(QTcpSocket *socket, QString userAccount,QObject *parent)
    :QObject(parent),userAccount(userAccount),socket(socket)
{
    //连接读取数据包
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(readyReadSlot()));

    connect(socket,SIGNAL(disconnected()),
            this,SLOT(socketDisconnectSlot()));

    qRegisterMetaType<QVariant>("QVariant"); //写在构造函数里
}

//接收到数据包判断类型
void SocketInfo::readyReadSlot()
{
    pack_t pack;
    memset(&pack, 0, sizeof(pack));
    //读取套接字中的数据包
    while(socket->read((char*)&pack, sizeof(pack)) > 0)
    {
        //qDebug()<<pack.account<<"----"<<pack.passwd;
        //判断类型
         switch(pack.type)
         {
            case REGISER_CNKI:
                userCnki(pack);
                break;
            case REGISTER_APP:
                registerUser(pack);
                break;
            case LOGIN_APP:
                loginUser(pack);
                break;
            case LIVE_START:
                openLive(pack);
                break;
            case JOIN_ROOM:
                joinRoom(pack);
                break;
            case SEND_MESSAGE:
                sendMessage(pack);
                break;
            case VISITOR_QUIT:
                visitorQuit(pack);
                break;
            case HOST_QUIT:
                hostQuit(pack);
                break;
            default:
                break;
         }
     }
}

//用户登录
void SocketInfo::loginUser(pack_t pack)
{
    QString qAccount = QString::fromLocal8Bit(pack.account);
    QString qPasswd = QString::fromLocal8Bit(pack.passwd);
    UserHandle uh;
    SocketManager* instance = SocketManager::getInstance();
    //qDebug() << "登陆：" << qAccount;
    if(!uh.hasRecordByAccount(qAccount))
    {
        pack.type = LOGIN_FAIL;
        strcpy(pack.chatInfo,"账号、密码输入错误");
        QVariant DataVar;
        DataVar.setValue(pack);
        emit sigInfoWrite(socket,DataVar,sizeof(pack));
        return;
    }else if(!uh.judgeUser(qAccount,qPasswd))
    {
        pack.type = LOGIN_FAIL;
        strcpy(pack.chatInfo,"密码输入错误");
        QVariant DataVar;
        DataVar.setValue(pack);
        emit sigInfoWrite(socket,DataVar,sizeof(pack));
        return;
    }else
    {
        QString Account = QString::fromLocal8Bit(pack.account);
        if((instance->selectOnlineAccount(Account)))
        {
            pack.type = LOGIN_FAIL;
            strcpy(pack.chatInfo,"该账号已登录");
            QVariant DataVar;
            DataVar.setValue(pack);
            emit sigInfoWrite(socket,DataVar,sizeof(pack));
            return;
        }else{
            pack.type = LOGIN_SUCCESS;
            instance->addOnlineUser(socket);
            userAccount = QString::fromLocal8Bit(pack.account);
            instance->addOnlineAccount(userAccount);
            QVariant DataVar;
            DataVar.setValue(pack);
            emit sigInfoWrite(socket,DataVar,sizeof(pack));
            refreshRoomListForOne();
         }
     }
}

//获取客户端套接字
QTcpSocket* SocketInfo::getSocket()const
{
    return socket;
}

//注册查重
void SocketInfo::userCnki(pack_t pack)
{
    QString qAccount = QString::fromLocal8Bit(pack.account);
    UserHandle uh;
    if(uh.hasRecordByAccount(qAccount))
    {
        pack.type = REGISER_CNKI;

        strcpy(pack.chatInfo,"该账号已注册，您可以直接登录或");
    }else
    {
        pack.type = REGISER_CNKI;
        strcpy(pack.chatInfo,"该账号可用");
    }
    QVariant DataVar;
    DataVar.setValue(pack);
    emit sigInfoWrite(socket,DataVar,sizeof(pack));
}

//注册用户方法，传入注册用户包
void SocketInfo::registerUser(pack_t pack)
{
    QString qAccount = QString::fromLocal8Bit(pack.account);
    QString qPasswd = QString::fromLocal8Bit(pack.passwd);
    User user(qAccount, qPasswd);
    UserHandle uh;
    bool insertRet  = uh.insertUser(user);
    if(!insertRet){
        pack.type = REGISTER_FAIL;
    }else{
        pack.type = REGISTER_SUCCESS;
    }

    QVariant DataVar;
    DataVar.setValue(pack);
    emit sigInfoWrite(socket,DataVar,sizeof(pack));
}

//开启直播
void SocketInfo::openLive(pack_t pack)
{
    qDebug() << "openLive";
    LiveRoomList* instance = LiveRoomList::getInstance();
    OneLiveRoom* room = new OneLiveRoom();
    vector <OneLiveRoom*> roomlist = instance->getAllRoom();
    vector <OneLiveRoom*>::iterator it_roomlist;
    for(it_roomlist = roomlist.begin();it_roomlist != roomlist.end();it_roomlist++)
    {
        if(((*it_roomlist)->getHostAccount()) == pack.account)
        {
            pack.type = LIVE_SUCCESS;
            QString udpAddress = (*it_roomlist)->getUdpAddress();
            QByteArray byte_chatInfo = udpAddress.toLocal8Bit();
            const char* c_chatInfo = byte_chatInfo.data();
            strcpy(pack.chatInfo,c_chatInfo);

            QVariant DataVar;
            DataVar.setValue(pack);
            emit sigInfoWrite(socket,DataVar,sizeof(pack));
//            refreshRoomList(); //刷新所有用户房间列表
            return;
        }
    }
    room->setHostAccount(userAccount);
    room->addVisitor(socket,userAccount);   //??? memcpy
    QString add = distributionAddress();    //分配udp组播地址
    room->setUdpAddress(add);
    instance->insertLiveRoomList(room);
    //创建房间成功
    pack.type = LIVE_SUCCESS;
    QByteArray byte_chatInfo = add.toLocal8Bit();
    const char* c_chatInfo = byte_chatInfo.data();
    strcpy(pack.chatInfo,c_chatInfo);

    QVariant DataVar;
    DataVar.setValue(pack);
    emit sigInfoWrite(socket,DataVar,sizeof(pack));

    refreshRoomList(); //刷新所有用户房间列表
}

//分配udp的组播地址
QString SocketInfo::distributionAddress()
{
//    224.0.0.0～224.0.0.255为预留的组播地址（永久组地址），地址224.0.0.0保留不做分配，其它地址供路由协议使用；
//    224.0.1.0～224.0.1.255是公用组播地址，可以用于Internet；
//    224.0.2.0～238.255.255.255为用户可用的组播地址（临时组地址），全网范围内有效；
//    239.0.0.0～239.255.255.255为本地管理组播地址，仅在特定的本地范围内有效。
    //使用224.0.2.1～238.255.255.254
    int add[4] = {0};
    add[3] = 224;
    add[2] = 0;
    add[1] = 2;
    add[0] = 1;
    static unsigned long long ipAddress = add[3]*256*256*256 + add[1]*256 + add[0];
    if(ipAddress == 238*256*256*256+255*256*256+255*256+255)
    {
        ipAddress = add[3]*256*256*256 + add[1]*256 + add[0];
    }
    unsigned long long IP = ipAddress;
    add[0] = IP%256;
    IP /= 256;
    add[1] = IP%256;
    IP /= 256;
    add[2] = IP%256;
    IP /= 256;
    add[3] = IP%256;
    IP /= 256;

    QString udpAddress = QString::number(add[3]);
    udpAddress += ".";
    udpAddress += QString::number(add[2]);
    udpAddress += ".";
    udpAddress += QString::number(add[1]);
    udpAddress += ".";
    udpAddress += QString::number(add[0]);

    ipAddress++;
    qDebug() << "udpAddress = "<< udpAddress;
    return udpAddress;
}

//刷新所有用户房间列表
void SocketInfo::refreshRoomList()
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = REFRESH_ROOMLIST;

    SocketManager* instance = SocketManager::getInstance();
    vector <QTcpSocket*> online = instance->getAllOnlineUser();
    vector <QTcpSocket*>::iterator it_online;

    for(it_online = online.begin();it_online != online.end();it_online ++)
    {
       QByteArray byte_account = userAccount.toLocal8Bit();
       const char* c_account = byte_account.data();
       strcpy(pack.account,c_account);
       strcpy(pack.chatInfo,"shuaxin");
       QVariant DataVar;
       DataVar.setValue(pack);
       emit sigInfoWrite((*it_online),DataVar,sizeof(pack));
    }
}

//刷新当前用户的房间列表
void SocketInfo::refreshRoomListForOne()
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = REFRESH_ROOMLIST;
    //qDebug() << "刷新";
    LiveRoomList* rlist = LiveRoomList::getInstance();
    vector <OneLiveRoom*> roomList = rlist->getAllRoom();
    vector <OneLiveRoom*>::iterator it_roomlist;
    for(it_roomlist = roomList.begin();it_roomlist != roomList.end();it_roomlist++)
    {
        QString qAccount = (*it_roomlist)->getHostAccount();
        QByteArray byte_account = qAccount.toLocal8Bit();
        const char* c_account = byte_account.data();
        strcpy(pack.account,c_account);
        strcpy(pack.chatInfo,"shuaxin");
        QVariant DataVar;
        DataVar.setValue(pack);
        emit sigInfoWrite(socket,DataVar,sizeof(pack));
    }
}

//加入房间
void SocketInfo::joinRoom(pack_t pack)
{
    QString hostAccount = QString::fromLocal8Bit(pack.account);
    LiveRoomList* instance = LiveRoomList::getInstance();
    vector<OneLiveRoom*> roomlist = instance->getAllRoom();
    vector<OneLiveRoom*>::iterator it_roomlist;

    for(it_roomlist = roomlist.begin();it_roomlist != roomlist.end();it_roomlist++)
    {
        if(hostAccount == (*it_roomlist)->getHostAccount())
        {
            (*it_roomlist)->addVisitor(socket,userAccount);
            pack.type = JOIN_ROOM_SUCCESS;
            QString udpAddress = (*it_roomlist)->getUdpAddress();
            QByteArray byte_chatInfo = udpAddress.toLocal8Bit();
            const char* c_chatInfo = byte_chatInfo.data();
            strcpy(pack.chatInfo,c_chatInfo);
            QVariant DataVar;
            DataVar.setValue(pack);
            emit sigInfoWrite(socket,DataVar,sizeof(pack));
            return;
        }
    }
}

 //发送消息
void SocketInfo::sendMessage(pack_t pack)
{
    QString hostAccount = QString::fromLocal8Bit(pack.account);

    LiveRoomList* instance = LiveRoomList::getInstance();
    vector<OneLiveRoom*> roomlist = instance->getAllRoom();
    vector<OneLiveRoom*>::iterator it_roomlist;
    pack.type = RECEIVE_MESSAGE;

    QByteArray byte_account = userAccount.toLocal8Bit();
    const char* c_account = byte_account.data();
    strcpy(pack.account,c_account);

    for(it_roomlist = roomlist.begin();it_roomlist != roomlist.end();it_roomlist++)
    {
        if(hostAccount == (*it_roomlist)->getHostAccount())
        {
            vector<visitor_t*> roomInfo = (*it_roomlist)->getAllUser();
            vector<visitor_t*>::iterator it_roomInfo;
            for(it_roomInfo = roomInfo.begin();it_roomInfo != roomInfo.end();it_roomInfo++)
            { 
                QVariant DataVar;
                DataVar.setValue(pack);
                emit sigInfoWrite((*it_roomInfo)->userSocket,DataVar,sizeof(pack));
            }
            return;
        }
    }
}


//游客退出直播间
void SocketInfo::visitorQuit(pack_t pack)
{
    QString hostAccount = QString::fromLocal8Bit(pack.account);
    LiveRoomList* instance = LiveRoomList::getInstance();
    vector<OneLiveRoom*> roomlist = instance->getAllRoom();
    vector<OneLiveRoom*>::iterator it_roomlist;
    for(it_roomlist = roomlist.begin();it_roomlist != roomlist.end();it_roomlist++)
    {
        if(hostAccount == (*it_roomlist)->getHostAccount())
        {
            (*it_roomlist)->removeVisitor(userAccount); //移除用户出房间
            vector<visitor_t*> roomInfo = (*it_roomlist)->getAllUser();
            if(roomInfo.empty())
            {
                SocketManager* sM = SocketManager::getInstance();
                vector <QTcpSocket*> online = sM->getAllOnlineUser();
                vector <QTcpSocket*>::iterator it_online;
                pack.type = ROOM_CLOSE;
                strcpy(pack.chatInfo,"roomclose");
                QVariant DataVar;
                DataVar.setValue(pack);

                for(it_online = online.begin();it_online != online.end();it_online ++)
                {
                   emit sigInfoWrite((*it_online),DataVar,sizeof(pack));
                }
                instance->removeLiveRoomList((*it_roomlist));
            }
            return;
        }
    }
}

//主播退出直播间
void SocketInfo::hostQuit(pack_t pack)
{
    LiveRoomList* instance = LiveRoomList::getInstance();
    vector<OneLiveRoom*> roomlist = instance->getAllRoom();
    vector<OneLiveRoom*>::iterator it_roomlist;

    for(it_roomlist = roomlist.begin();it_roomlist != roomlist.end();it_roomlist++)
    {
        if(userAccount == (*it_roomlist)->getHostAccount())
        {
            (*it_roomlist)->removeVisitor(userAccount);  //主播移除房间
            vector<visitor_t*> roomInfo = (*it_roomlist)->getAllUser();
            if(roomInfo.empty())
            {
                SocketManager* sM = SocketManager::getInstance();
                vector <QTcpSocket*> online = sM->getAllOnlineUser();
                vector <QTcpSocket*>::iterator it_online;
                pack.type = ROOM_CLOSE;
                QByteArray byte_account = userAccount.toLocal8Bit();
                const char* c_account = byte_account.data();
                strcpy(pack.account,c_account);
                strcpy(pack.chatInfo,"roomclose");
                QVariant DataVar;
                DataVar.setValue(pack);
                for(it_online = online.begin();it_online != online.end();it_online ++)
                {
                   emit sigInfoWrite((*it_online),DataVar,sizeof(pack));
                }
                instance->removeLiveRoomList((*it_roomlist));
            }else{
                pack.type = NOTICE_HOSTQUIT;
                QVariant DataVar;
                DataVar.setValue(pack);
                vector<visitor_t*> roomInfo = (*it_roomlist)->getAllUser();
                vector<visitor_t*>::iterator it_roomInfo;
                for(it_roomInfo = roomInfo.begin();it_roomInfo != roomInfo.end();it_roomInfo++)
                {
                    emit sigInfoWrite((*it_roomInfo)->userSocket,DataVar,sizeof(pack));
                }
            }
            return;
        }
    }
}

//客户端退出
void SocketInfo::socketDisconnectSlot()
{
    SocketManager* instance = SocketManager::getInstance();
    instance->removeOnlineUser(socket);
    instance->removeSocketInfo(socket);
    instance->removeOnlineAccount(userAccount);
    QThread* th = QThread::currentThread();
    emit sigClientLogout(th);
}





