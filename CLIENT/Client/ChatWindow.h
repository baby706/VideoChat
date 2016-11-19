#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "LiveWindow.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "package.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(QString,QWidget *parent = 0);
    ~ChatWindow();

signals:
    void sigStartLive();
    void sigJoinRoom(QString,QColor );

private slots:
    void on_btn_startLive_clicked();

    void on_btn_close_clicked();

    void sigRefreshListSlot(QString &);

    void itemDoubleClickedSlot( QListWidgetItem*);

    void sigRoomClose(QString&);

private:
    QString ownerName;
    LiveWindow* liveRoom;
    Ui::ChatWindow *ui;
};

#endif // CHATWINDOW_H
