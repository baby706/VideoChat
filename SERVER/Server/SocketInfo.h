#ifndef SOCKETINFO_H
#define SOCKETINFO_H

#include <QObject>
#include <QTcpSocket>
#include "package.h"
#include <vector>
#include <QVariant>
#include <QThread>
using namespace std;

class SocketInfo : public QObject
{
    Q_OBJECT
public:
    explicit SocketInfo(QTcpSocket *socket, QString userAccount = 0,QObject *parent = 0);
    QTcpSocket* getSocket()const;            //获取客户端套接字
    void userCnki(pack_t);                  //查重用户账号
    void registerUser(pack_t);              //注册用户方法，传入注册用户包
    void loginUser(pack_t);                 //用户登录
    void openLive(pack_t);                  //开启直播
    void refreshRoomList();                  //刷新所有用户房间列表
    void refreshRoomListForOne();            //刷新当前用户的房间列表
    void joinRoom(pack_t);                  //加入房间
    void sendMessage(pack_t);               //发送消息
    void visitorQuit(pack_t);               //游客退出房间
    void hostQuit(pack_t);                   //主播退出房间
    QString distributionAddress();           //分配udp的组播地址

signals:
    void sigInfoWrite(QTcpSocket*, QVariant, qint64);  //交由主线程发送数据包的信号
    void sigJoinRoomSuccess();   //
    void sigClientLogout(QThread*);
public slots:
    void readyReadSlot();                    //接收到数据包判断类型
    void socketDisconnectSlot();             //客户端退出
private:
    QString userAccount;                     //用户账号
    QTcpSocket *socket;                      //套接字

};

#endif // SOCKETINFO_H
