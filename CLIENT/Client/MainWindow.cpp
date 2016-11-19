#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QHostAddress>
#include "package.h"
#include <QMessageBox>
#include <string.h>
#include "Register.h"
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QColor>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1、创建套接字对象
    clientSocket = new QTcpSocket(this);
    //2、链接服务器
    QObject::connect(clientSocket,SIGNAL(error(QAbstractSocket::SocketError)),
                     this,SLOT(onErr(QAbstractSocket::SocketError)));
    clientSocket->connectToHost(QHostAddress::LocalHost, 9999);
    connect(clientSocket, SIGNAL(readyRead()),
            this, SLOT(readyReadSlot()));

    setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(ui->label->size()); // 禁止改变窗口大小。
    setWindowTitle("天蝎");
    setWindowIcon(QIcon(":/image/图标.jpg"));

    //ui->le_account->setPlaceholderText("请输入账号");
    ui->com_accout->lineEdit()->setPlaceholderText("请输入账号");
    ui->le_passwd->setPlaceholderText("请输入密码");
    ui->le_passwd->setEchoMode (QLineEdit::Password);  //密码隐藏
    //ui->com_accout->setEditable(true);
}

//读取数据包
void MainWindow::readyReadSlot()
{
    //qDebug()<<"onreadyRead";
    pack_t pack;
    memset(&pack, 0, sizeof(pack));
    while(clientSocket->read((char*)&pack, sizeof(pack)) > 0)
    {
        QString type = QString::number(pack.type);
        qDebug() << "type:"<<type<<"acc:"<<pack.account<<"chainfo:"<<pack.chatInfo;
        switch (pack.type)
        {
            case REGISER_CNKI:
            {
                QString message = QString::fromLocal8Bit(pack.chatInfo);
                emit sigRegisterCnki(message);
                break;
            }
            case REGISTER_FAIL:
                 QMessageBox::warning(this, "提示", "注册失败");
                 regist->close();
                 break;
            case REGISTER_SUCCESS:
                 QMessageBox::warning(this, "提示", "注册成功");
                 regist->close();
                 break;
            case LOGIN_FAIL:
            {
                 QMessageBox::warning(this,"提示","登录失败");
                 QString message = QString::fromLocal8Bit(pack.chatInfo);
                 ui->lab_warning->setText(message);
                 break;
            }
            case LOGIN_SUCCESS:
            {
                 LoginSuccess(pack);
                 break;
            }
            case LIVE_SUCCESS:
            {
                LiveSuccess(pack);
                break;
            }
            case LIVE_ALREADY:
                QMessageBox::critical(this, "提示", "开启直播失败");
                break;
            case REFRESH_ROOMLIST:
            {
                QString qAccount = QString::fromLocal8Bit(pack.account);
                emit sigRefreshList(qAccount);
                qDebug() << "refresh";
                break;
            }
            case JOIN_ROOM_SUCCESS:
            {
                JoinRoomSuccess(pack);
                break;
            }
            case RECEIVE_MESSAGE:
            {
                emit sigReceiveMessage(pack);
                break;
            }
            case NOTICE_HOSTQUIT:
                emit sigNoticeHostQuit();
                break;
            case ROOM_CLOSE:
            {
                QString host = QString::fromLocal8Bit(pack.account);
                emit sigRoomClose(host);
                break;
            }
            default:
                 break;
        }
    }
}

void MainWindow::onErr(QAbstractSocket::SocketError )
{
    QMessageBox::critical(this,"warning","socket error");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//登录
void MainWindow::on_btn_login_clicked()
{
    ui->lab_warning->clear();
    QString myAccount = ui->com_accout->currentText();
    QString myPasswd = ui->le_passwd->text();

    if(myAccount.isEmpty())
    {
        ui->lab_warning->setText("请输入账号，密码");
        return;
    }
    if(myPasswd.isEmpty())
    {
        if(myAccount.isEmpty())
        {
           ui->lab_warning->setText("请输入账号，密码");
           return;
        }else
        {
           ui->lab_warning->setText("请输入密码");
           return;
        }
    }
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = LOGIN_APP;
    //qDebug() << "myAccount = " << myAccount;
    QByteArray byte_account = myAccount.toLocal8Bit();
    QByteArray byte_passwd = myPasswd.toLocal8Bit();
    const char* c_account = byte_account.data();
    const char* c_passwd = byte_passwd.data();
    strcpy(pack.account,c_account);
    strcpy(pack.passwd,c_passwd);
    //qDebug() << "pack.account = " << pack.account;
    clientSocket->write((char*)&pack,sizeof(pack));
}

//登录成功
void MainWindow::LoginSuccess(pack_t pack)
{
    /*需要写本地保存?????*/
    ui->com_accout->addItem(QWidget::tr(pack.account));
    this->hide();
    userAccount = QString::fromLocal8Bit(pack.account);
    userPasswd = QString::fromLocal8Bit(pack.passwd);
    //qDebug() << "login " << pack.account <<"------"<< pack.passwd;
    chat = new ChatWindow(userAccount);
    chat->show();
    connect(this,SIGNAL(sigRefreshList(QString&)),
            chat,SLOT(sigRefreshListSlot(QString&)));
    connect(chat,SIGNAL(sigStartLive()),
            this,SLOT(sigStartLiveSlot()));
    connect(chat,SIGNAL(sigJoinRoom(QString,QColor)),
            this,SLOT(sigJoinRoomSlot(QString,QColor)));
    connect(this,SIGNAL(sigRoomClose(QString&)),
            chat,SLOT(sigRoomClose(QString&)));
}

//注册
void MainWindow::on_btn_register_clicked()
{
    regist = new Register(this);
    regist->show();
    connect(regist,SIGNAL(sigRegister(QString&,QString&)),
            this,SLOT(sigRegisterSlot(QString&,QString&)));
    connect(regist,SIGNAL(sigCnki(QString&)),
            this,SLOT(sigCnkiSlot(QString&)));
    connect(this,SIGNAL(sigRegisterCnki(QString&)),
            regist,SLOT(registerCnkiSlot(QString&)));
}

//发送注册查重数据包
void MainWindow::sigCnkiSlot(QString& qAccount)
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = REGISER_CNKI;
    QByteArray byte_account = qAccount.toLocal8Bit();
    const char* c_account = byte_account.data();
    strcpy(pack.account,c_account);

    clientSocket->write((char*)&pack,sizeof(pack));
}

//发送注册数据包
void MainWindow::sigRegisterSlot(QString &qAccount,QString &qPasswd)
{
    qDebug()<<qAccount<<"==="<<qPasswd;
    //将数据放入到数据包中
    pack_t pack;
    memset(&pack, 0, sizeof(pack));
    pack.type = REGISTER_APP;

    QByteArray byte_account = qAccount.toLocal8Bit();
    QByteArray byte_passwd = qPasswd.toLocal8Bit();
    const char* c_account = byte_account.data();
    const char* c_passwd = byte_passwd.data();
    strcpy(pack.account,c_account);
    strcpy(pack.passwd,c_passwd);

    //将数据发送到服务器
    clientSocket->write((char*)&pack, sizeof(pack));
    //qDebug()<<pack.account<<"---"<<pack.passwd;
}

//发送开启直播间的槽
void MainWindow::sigStartLiveSlot()
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = LIVE_START;
    QByteArray byte_account = userAccount.toLocal8Bit();
    const char* c_account = byte_account.data();

    strcpy(pack.account, c_account);

    clientSocket->write((char*)&pack, sizeof(pack));
}

//开启直播成功
void MainWindow::LiveSuccess(pack_t pack)
{
    QString udpAddress = QString::fromLocal8Bit(pack.chatInfo);
    liveRoom = new LiveWindow(1,this->getUserAccount(),udpAddress);
    liveRoom->show();
    chat->hide();
    connect(liveRoom,SIGNAL(sigSendMessage(QString&,QString &)),
            this,SLOT(sigSendMessageSlot(QString&,QString&)));
    connect(this,SIGNAL(sigReceiveMessage(pack_t)),
            liveRoom,SLOT(sigReceiveMessageSlot(pack_t)));
    connect(liveRoom,SIGNAL(sigHostQuit()),
            this,SLOT(sigHostQuitSlot()));
}

//加入房间成功
void MainWindow::JoinRoomSuccess(pack_t pack)
{
    QString qAccount = QString::fromLocal8Bit(pack.account);
    QString udpAddress = QString::fromLocal8Bit(pack.chatInfo);
    liveRoom = new LiveWindow(0,qAccount,udpAddress);
    liveRoom->show();
    chat->hide();
    connect(liveRoom,SIGNAL(sigSendMessage(QString&,QString&)),
            this,SLOT(sigSendMessageSlot(QString&,QString&)));
    connect(this,SIGNAL(sigReceiveMessage(pack_t)),
            liveRoom,SLOT(sigReceiveMessageSlot(pack_t)));
    connect(liveRoom,SIGNAL(sigVisitorQuit(QString)),
            this,SLOT(sigVisitorQuitSlot(QString)));
    connect(this,SIGNAL(sigNoticeHostQuit()),
            liveRoom,SLOT(sigNoticeHostQuitSlot()));
}

//发送加入直播间的槽
void MainWindow::sigJoinRoomSlot(QString qAccount,QColor itColor)
{
    //QColor co(gray);
    if(itColor == Qt::gray)
    {
        QMessageBox::warning(this, "提示", "直播房间已关闭");
        return;
    }
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = JOIN_ROOM;

    QByteArray byte_account = qAccount.toLocal8Bit();
    const char* c_account = byte_account.data();
    strcpy(pack.account,c_account);
    //qDebug() << "send join room" << pack.account;

    if(qAccount == userAccount)
    {
        pack.type = LIVE_START;
    }

    clientSocket->write((char*)&pack, sizeof(pack));
}

//发送聊天信息的槽
void MainWindow::sigSendMessageSlot(QString &message,QString &host)
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));
    pack.type = SEND_MESSAGE;

    QByteArray byte_account = host.toLocal8Bit();
    const char* c_account = byte_account.data();
    strcpy(pack.account,c_account);

    QByteArray byte_chatInfo = message.toLocal8Bit();
    const char* c_chatInfo = byte_chatInfo.data();
    strcpy(pack.chatInfo,c_chatInfo);

    clientSocket->write((char*)&pack, sizeof(pack));
}

//游客退出直播间的槽
void MainWindow::sigVisitorQuitSlot(QString hostAccount)
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));

    pack.type = VISITOR_QUIT;
    QByteArray byte_account = hostAccount.toLocal8Bit();
    const char* c_account = byte_account.data();
    strcpy(pack.account,c_account);

    clientSocket->write((char*)&pack, sizeof(pack));
    chat->show();
}

//主播退出直播间
void MainWindow::sigHostQuitSlot()
{
    pack_t pack;
    memset(&pack,0,sizeof(pack));

    pack.type = HOST_QUIT;
    clientSocket->write((char*)&pack, sizeof(pack));
    chat->show();
}
