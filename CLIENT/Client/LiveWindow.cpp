#include "LiveWindow.h"
#include "ui_LiveWindow.h"
#include <QString>
#include <QHBoxLayout>
#include <QListView>
#include <QStringListModel>
#include <QCameraInfo>
#include <QHostAddress>
#include <QVideoFrame>
#include "videosurface.h"
#include "videopackage.h"
#include "Danmu.h"
#include <QTimer>
#include <QScreen>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>

LiveWindow::LiveWindow(int Flag,QString hostAccount,QString address,QWidget *parent) :
    QWidget(parent),Flag(Flag),hostAccount(hostAccount),address(address),
    ui(new Ui::LiveWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose); //当窗口关闭时，销毁窗口
    setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(ui->lab_back->size()); // 禁止改变窗口大小。

    ui->le_send->setPlaceholderText("请在这里输入类容");
    ui->la_hostName->setText(hostAccount);
    ui->te_show->setEnabled(false);
    ui->cbox_camera->setCheckable(true);
    ui->chox_table->setCheckable(true);
    ui->chox_mic->setCheckable(true);
    ui->chox_danmu->setCheckable(true);
    Danmuflag = 0;
    setWindowTitle(hostAccount);
    setWindowIcon(QIcon(":/image/图标.jpg"));
    time_Desktop = new QTimer(this);
    connect(time_Desktop,SIGNAL(timeout()),
             this,SLOT(showDesktopSlot()));

    if(!Flag)   //游客界面
    {
        ui->la_flag->hide();
        ui->cbox_camera->hide();
        ui->lab_cameraFlag->hide();
        ui->lab_micFlag->hide();
        ui->chox_mic->hide();
        ui->lab_tabFlag->hide();
        ui->chox_table->hide();
        QPixmap img(":/image/直播界面.jpg");
        ui->lab_show_host->setPixmap(img);
        ui->lab_show_host->setScaledContents(true);
    }else       //主播界面
    {
        ui->la_flag->show();
        ui->lab_show_host->show();
    }
    setUdp(); //设置摄像头数据以及udp传输
}

//设置udp传输视频数据的信息
void LiveWindow::setUdp()
{
    QCameraInfo info = QCameraInfo::defaultCamera();
    camera = new QCamera(info, this);
    VideoSurface *vf = new VideoSurface(this);
    camera->setViewfinder(vf);
    connect(vf, SIGNAL(videoChanged(QVideoFrame)),
                this, SLOT(videoChangedSlot(QVideoFrame)));
    socketWrite = new QUdpSocket(this);
    socketRead = new QUdpSocket(this);
    //groupAddress.setAddress("239.88.88.88");
    groupAddress.setAddress(address);
    socketWrite->setSocketOption(QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRead->bind(QHostAddress::AnyIPv4,9999,QUdpSocket::ReuseAddressHint | QUdpSocket::ShareAddress);
    qDebug() << "bind - hostAddress:" << groupAddress.toString();
    socketRead->joinMulticastGroup(groupAddress);//添加到组
    connect(socketRead,SIGNAL(readyRead()),
            this,SLOT(onReadyReadSocket()));
}

LiveWindow::~LiveWindow()
{
    delete ui;
}

//发送聊天消息
void LiveWindow::on_btn_send_clicked()
{
    QString message = ui->le_send->text();
    if(message.isEmpty())
    {
        return;
    }
    ui->le_send->clear();
    QString &host = this->getRoomAccount();
    emit sigSendMessage(message,host);
}

//显示消息的槽
void LiveWindow::sigReceiveMessageSlot(pack_t pack)
{
    QString account = QString::fromLocal8Bit(pack.account);
    QString message = QString::fromLocal8Bit(pack.chatInfo);
    ui->te_show->append(account);
    ui->te_show->insertPlainText(" : ");
    ui->te_show->moveCursor(QTextCursor::End);
    ui->te_show->insertPlainText(message);
    ui->te_show->moveCursor(QTextCursor::End);
    QRect rect = ui->lab_show_host->rect();
    if(Danmuflag)
        Danmu *danmu = new Danmu(ui->lab_show_host,message,"Red",1,rect);
}

//弹幕开关
void LiveWindow::on_chox_danmu_clicked()
{
    if(ui->chox_danmu->isChecked())
    {
        QPixmap img(":/image/开关开.png");
        ui->lab_danmu->setPixmap(img);
        Danmuflag = 1;
    }else
    {
        QPixmap img(":/image/开关关.png");
        ui->lab_danmu->setPixmap(img);
        Danmuflag = 0;
    }
}

//窗口关闭事件
void LiveWindow::closeEvent(QCloseEvent *) //此函数在QWidget关闭时执行
{
    //主播离开房间
    if(Flag == 1)
    {
        emit sigHostQuit();
    }else   //游客退出房间
    {
        emit sigVisitorQuit(hostAccount);
    }
}

//接收到主播离开通知
void LiveWindow::sigNoticeHostQuitSlot()
{
    ui->te_show->append("系统消息: 主播已离开直播间。");
}

//直播桌面
void LiveWindow::on_chox_table_clicked()
{
    qDebug()<<"boxchecked";
    if(ui->chox_table->isChecked())
    {
        if(ui->cbox_camera->isChecked())
        {
            ui->cbox_camera->setChecked(false);
            on_cbox_camera_clicked();
        }
        time_Desktop->start(50); // 50ms单触发定时器
    }else
    {
        time_Desktop->stop();
        QImage image(":/image/直播界面.jpg");
        image = image.scaled(640,480);
        sendUdp(image);
        ui->lab_show_host->clear();
    }
}

//开启摄像头
void LiveWindow::on_cbox_camera_clicked()
{
    qDebug() << "camera open";
    if(ui->cbox_camera->isChecked())
    {
        if(ui->chox_table->isChecked())
        {
            ui->chox_table->setChecked(false);
            on_chox_table_clicked();
        }
        camera->start();
        ui->lab_cameraFlag->show();
    }else
    {
        camera->stop();
        QImage image(":/image/直播界面.jpg");
        image = image.scaled(640,480);
        sendUdp(image);
        ui->lab_show_host->clear();
    }
}

//分享桌面
void LiveWindow::showDesktopSlot()
{
    qDebug() << "showDeskstop";
    QScreen *scr = QApplication::primaryScreen();
    QPixmap pm = scr->grabWindow(QApplication::desktop()->winId());
    QImage image = pm.toImage();
    QPixmap p = QPixmap::fromImage(image);
    qDebug() << "showDeskstop2";
    ui->lab_show_host->setPixmap(p.scaled(ui->lab_show_host->size()));
    image = image.scaled(640,480);
    qDebug() << "showDeskstop3";
    sendUdp(image);
}

//捕捉到摄像头图片并发送UDP数据
void LiveWindow::videoChangedSlot(QVideoFrame curFrama)
{
    static unsigned int i = 0;      //控制帧数
    i++;
    QVideoFrame frame(curFrama);
    frame.map(QAbstractVideoBuffer::ReadOnly);
    //通过QVideoFrame对象构建QImage对象
    QImage image(frame.bits(),
                 frame.width(),
                 frame.height(),
                 QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));
    //将图像旋转180
    QMatrix matrix;
    matrix.rotate(180);
    image = image.transformed(matrix);


    //显示图片
    if(Flag)
    {
        QPixmap pixmap = QPixmap::fromImage(image);
        pixmap = pixmap.scaled(ui->lab_show_host->size());
        ui->lab_show_host->setPixmap(pixmap);
    }
    //image = image.scaled(400,300);
    if(i % 4 != 0)
        return;
    else
        sendUdp(image);
}

//udp发送
void LiveWindow::sendUdp(QImage image)
{
    int unitBytes = 4096;
    //image = image.scaled(500,300);
    int byteCount = image.byteCount();//图片大小
    int width = image.width();
    int height = image.height();
    int bytePerLine = image.bytesPerLine();//每行字节数
    qDebug()<<"byteCount:"<<byteCount;
    qDebug()<<"width:"<<width;
    qDebug()<<"height:"<<height;
    qDebug()<<"bytePerLine:"<<bytePerLine;
    int writeBytes = 0;
    //uchar*data = image.bits();//把图片转化为二进制流存放到data指向的空间
    while(true)
    {
        ImagePackage_t pack;
        memset(&pack,0,sizeof(ImagePackage_t));

        pack.width = width;
        pack.height = height;
        pack.bytesPerline = bytePerLine;
        if(writeBytes<byteCount)
        {
            memcpy(pack.data,(char*)image.bits()+writeBytes,unitBytes);
            pack.packTaken = unitBytes;
            writeBytes += unitBytes;
            if(writeBytes>=byteCount)
            {
                pack.isLastPack = true;
                pack.packTaken = unitBytes-writeBytes+byteCount;
                qDebug()<<"writeBytes:"<<writeBytes;

            }else
            {
                pack.isLastPack = false;
                pack.packTaken = unitBytes;
            }
            /*QHostAddress::Broadcast,*/
            qDebug() << "hostAddress:" << groupAddress.toString();
            socketWrite->writeDatagram((char*)&pack,
                                       sizeof(ImagePackage_t),
                                       groupAddress,
                                       9999);

        }else
        {
            break;
        }
    }
}

//接收UDP视频数据
void LiveWindow::onReadyReadSocket()
{
    qDebug()<<"接收UDP视频数据";

    static QByteArray *imageBytes = new QByteArray(2280000,0);//字符数组2280000字节，初始化为0
    static QDataStream *dataStream = new QDataStream(imageBytes,QIODevice::ReadWrite);//数据流指针指向数组的首地址，以读写格式
    //static int readed = 0;
    while(socketRead->hasPendingDatagrams())//udp下判断是否还有待读取的数据包，有返回true，无返回false
    {
        ImagePackage_t pack;
        memset(&pack,0,sizeof(ImagePackage_t));
        socketRead->readDatagram((char*)&pack,sizeof(ImagePackage_t));
        if(true == pack.isLastPack)
        {
            qDebug()<<"packTaken:"<<pack.packTaken;
            dataStream->writeRawData(pack.data,pack.packTaken);
            QImage image = QImage((uchar*)imageBytes->data(),
                                  pack.width,
                                  pack.height,
                                  pack.bytesPerline,
                                  QImage::Format_RGB32);

        QPixmap map = QPixmap::fromImage(image);//把image转化为map
        qDebug()<<"接收的图片大小:"<<image.byteCount();
        qDebug()<<"width"<<pack.width;
        qDebug()<<"height"<<pack.height;
        qDebug()<<"bytesPerline"<<pack.bytesPerline;

        if(!Flag)
        {
            map = map.scaled(ui->lab_show_host->size());
            ui->lab_show_host->setPixmap(map);//显示图片
        }
       dataStream->device()->seek(0);

        }else{
            dataStream->writeRawData(pack.data,pack.packTaken);

        }
    }
}

