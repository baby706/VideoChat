#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SocketInfo.h"
#include "SocketManager.h"
#include <QThread>
#include <QDebug>
#include <QVariant>
#include <QPixmap>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1、创建套接字管理对象
    tcpServer = new QTcpServer(this);

    //3、关联来自客户端的信号槽
    connect(tcpServer, SIGNAL(newConnection()),
            this, SLOT(newConnectionSlot()));

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(590,370); // 禁止改变窗口大小。
    setWindowTitle("天蝎直播服务器");
    setWindowIcon(QIcon(":/image/图标.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//开启服务器
void MainWindow::on_btn_start_clicked()
{
    //2、监听
    if(!tcpServer->isListening()){
        if(tcpServer->listen(QHostAddress::Any, 9999)){
            ui->te_show->append("listen success.");
        }else{
            ui->te_show->append("listen fail.");
        }
    }else{
        ui->te_show->append("already listen...");
    }

}

//客户端连接
void MainWindow::newConnectionSlot()
{
    ui->te_show->append("Has New Client Connect.");
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    SocketInfo *si = new SocketInfo(clientSocket);

    //主线程负责发送数据包，操作套接字
    connect(si, SIGNAL(sigInfoWrite(QTcpSocket*,
                                    QVariant,qint64)),
            this, SLOT(sigInfoWriteSlot(QTcpSocket*,
                                        QVariant,qint64)));

    connect(si,SIGNAL(sigClientLogout(QThread*)),
            this,SLOT(clientDisconnectSlot(QThread*)));

    QThread *th = new QThread(this);

    si->moveToThread(th);
    th->start();


    //将新的套接字添加进入容器
    SocketManager* instance = SocketManager::getInstance();
    instance->insertSocketInfo(si);
}

//给客户端发送数据包
void MainWindow::sigInfoWriteSlot(QTcpSocket* socket, QVariant massage, qint64 len)
{
    pack_t pack = massage.value<pack_t>();
    socket->write((char*)&pack,len);
    QString type = QString::number(pack.type);
    qDebug() <<"type:"<<type<<"pack_account" << pack.account << "-----" << pack.chatInfo;
}


//客户端断开连接
void MainWindow::clientDisconnectSlot(QThread* th)
{
    ui->te_show->append("One Client has disconnected");
    //qDebug() << "th" << QString::number(th);
    th->quit();
}


