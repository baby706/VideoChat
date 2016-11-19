#include "ChatWindow.h"
#include "ui_ChatWindow.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QPixmap>
#include <QDebug>
#include <QColor>


ChatWindow::ChatWindow(QString ownerName,QWidget *parent) :
    QWidget(parent),ownerName(ownerName),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(ownerName);
    connect(ui->list_room,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this,SLOT(itemDoubleClickedSlot(QListWidgetItem*)));
    setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);//隐藏最大化按钮
    setFixedSize(ui->label->size()); // 禁止改变窗口大小。

    ui->list_room->setStyleSheet("background-color:transparent");
    ui->list_room->setIconSize(QSize(100, 100));
    ui->list_room->setResizeMode(QListView::Adjust);
    ui->list_room->setMovement(QListView::Static); //设置QListWidget中的单元项不可被拖动
    ui->list_room->setViewMode(QListView::IconMode); //设置QListWidget的显示模式
    //ui->list_room->setFlow(QListView::TopToBottom);
    ui->list_room->setFlow(QListView::LeftToRight);  //横向显示
    ui->list_room->setSpacing(10); //设置QListWidget中的单元项的间距

    setWindowIcon(QIcon(":/image/图标.jpg"));
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_btn_startLive_clicked()
{
    emit sigStartLive();
}

void ChatWindow::on_btn_close_clicked()
{
    this->close();
}

void ChatWindow::sigRefreshListSlot(QString &hostAccount)
{
    QPixmap objPixmap(":/image/picture1.jpg");
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(100,100))),hostAccount);
    pItem->setSizeHint(QSize(100, 120));
    pItem->setTextColor(QColor(Qt::red));
    ui->list_room->insertItem(1,pItem);
    //ui->list_room->addItem(hostAccount);
}

void ChatWindow::itemDoubleClickedSlot(QListWidgetItem* pItem)
{
    //qDebug() << pItem->text();
    QColor itColor = pItem->textColor();
   emit sigJoinRoom(pItem->text(),itColor);
}

void ChatWindow::sigRoomClose(QString & host)
{
    QList<QListWidgetItem*> list;
    list = ui->list_room->findItems(host,Qt::MatchCaseSensitive);
    QListWidgetItem* sel = list[0];
    int r = ui->list_room->row(sel);

    QListWidgetItem* item = ui->list_room->takeItem(r);
    ui->list_room->removeItemWidget(item);
    delete item;
}
