#ifndef LIVEWINDOW_H
#define LIVEWINDOW_H

#include <QWidget>
#include "package.h"
#include <QDebug>
#include <QString>
#include <string.h>
#include <QCameraImageCapture>
#include <QCamera>
#include <QCameraViewfinder>
#include <QUdpSocket>
#include <QTimer>

namespace Ui {
class LiveWindow;
}

class LiveWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LiveWindow(int Flag,QString hostAccount,QString address,QWidget *parent = 0);
    ~LiveWindow();
    QString& getRoomAccount() {return hostAccount;}
    void setUdp();
    void sendUdp(QImage image);
    //void setHostAddress(QString);
signals:
    void sigSendMessage(QString&,QString & );
    void sigVisitorQuit(QString);
    void sigHostQuit();
protected:
    virtual void closeEvent(QCloseEvent *event);
private slots:
    void on_btn_send_clicked();
    void sigReceiveMessageSlot(pack_t);
    void sigNoticeHostQuitSlot();

    void videoChangedSlot(QVideoFrame);

    void onReadyReadSocket();

    void on_cbox_camera_clicked();

    void on_chox_table_clicked();

    void showDesktopSlot();

    void on_chox_danmu_clicked();

private:
    int Flag;           //标志，1代表主播，0代表游客
    int Danmuflag;      //1开，0关

    QString hostAccount;
    //定时器
    QTimer *time_Desktop;

    // 系统摄像设备（摄像头）
    QCamera *camera;
    // 摄像取景器部件
    QCameraViewfinder *cameraViewFinder;
    // 截图部件
    QCameraImageCapture *cameraImageCapture;

    QUdpSocket *socketWrite;

    QUdpSocket *socketRead;

    QString address;
    QHostAddress groupAddress;

    Ui::LiveWindow *ui;
};

#endif // LIVEWINDOW_H
