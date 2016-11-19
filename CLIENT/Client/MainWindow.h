#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include "Register.h"
#include "ChatWindow.h"
#include "LiveWindow.h"
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getUserAccount()const{return userAccount;}
    void LoginSuccess(pack_t);
    void LiveSuccess(pack_t);
    void JoinRoomSuccess(pack_t);
signals:
    void sigRegisterCnki(QString &);
    void sigRefreshList(QString&);
    void sigReceiveMessage(pack_t);
    void sigNoticeHostQuit();
    void sigRoomClose(QString&);

private slots:
    void on_btn_login_clicked();     //登录

    void on_btn_register_clicked();  //注册账号

    void readyReadSlot();    //读取数据包

    void onErr(QAbstractSocket::SocketError socketError);  //连接服务器失败

    void sigRegisterSlot(QString &,QString &);

    void sigCnkiSlot(QString &);

    void sigStartLiveSlot();

    void sigJoinRoomSlot(QString,QColor);

    void sigSendMessageSlot(QString&,QString &);

    void sigVisitorQuitSlot(QString);

    void sigHostQuitSlot();

private:
    QString userAccount;             //用户账号
    QString userPasswd;              //用户密码

    QTcpSocket* clientSocket;   //客户端套接字
    Register* regist;
    ChatWindow* chat;
    LiveWindow* liveRoom;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
