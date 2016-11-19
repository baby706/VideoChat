#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <vector>
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_start_clicked();           //开启服务器
    void newConnectionSlot();              //客户端连接
    void sigInfoWriteSlot(QTcpSocket*, QVariant , qint64);  //给客户端发送数据包
    void clientDisconnectSlot(QThread*);                 //客户端断开连接

private:
    QTcpServer *tcpServer;                 //server对象，用来与客户端通信
    Ui::MainWindow *ui; 
};

#endif // MAINWINDOW_H
