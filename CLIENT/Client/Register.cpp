#include "Register.h"
#include "ui_Register.h"
#include <QString>
#include <QPalette>
#include <QMessageBox>
#include <QDebug>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->le_accout->installEventFilter(this);
    ui->le_passwd->installEventFilter(this);
    ui->le_passwd2->installEventFilter(this);
    ui->le_coder->installEventFilter(this);

    connect(ui->le_accout,SIGNAL(LineEditClicked(MyLineEdit*)),
            this,SLOT(myLineEditClicked(MyLineEdit*)));
    connect(ui->le_passwd,SIGNAL(LineEditClicked(MyLineEdit*)),
            this,SLOT(myLineEditClicked(MyLineEdit*)));
    connect(ui->le_passwd2,SIGNAL(LineEditClicked(MyLineEdit*)),
            this,SLOT(myLineEditClicked(MyLineEdit*)));
    connect(ui->le_coder,SIGNAL(LineEditClicked(MyLineEdit*)),
            this,SLOT(myLineEditClicked(MyLineEdit*)));

    m_pCodeArea = new CodeArea(this);
    ui->cLayout->addWidget(m_pCodeArea);
    ui->btn_register->setEnabled(false);
    ui->ch_Box->setCheckable(true);
    ui->le_passwd->setEchoMode (QLineEdit::Password);  //密码隐藏
    ui->le_passwd2->setEchoMode (QLineEdit::Password);  //密码隐藏
    setWindowTitle("天蝎直播注册");
    setWindowIcon(QIcon(":/image/图标.jpg"));
    setFixedSize(ui->lab_back->size()); // 禁止改变窗口大小。
}

Register::~Register()
{
    delete ui;
}

//点击同意并注册按钮
void Register::on_btn_register_clicked()
{   
    QString myAccount = ui->le_accout->text();
    QString myPasswd = ui->le_passwd->text();
    QString myPasswd2 = ui->le_passwd2->text();
    if(myAccount.isEmpty())
    {
        ui->lab_acc->setText("账号不能为空");
        return;
    }
    if(myPasswd.isEmpty())
    {
        ui->lab_pwd->setText("密码不能为空");
        return;
    }
    if(myPasswd2.isEmpty())
    {
        ui->lab_pwd2->setText("请再次输入密码");
        return;
    }
    if(myPasswd != myPasswd2)
    {
        ui->lab_pwd2->setText("两次密码输入不一致");
        return;
    }
    if (!(m_pCodeArea->checkCode(ui->le_coder->text())))
    {
       ui->lab_coder->setText("验证码输入错误");
       ui->le_coder->clear();
       m_pCodeArea->replaceCodePic();
       return;
    }

    emit(sigRegister(myAccount,myPasswd));
}

//每次选中一个lineedit都将其颜色变为蓝色
bool Register::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->le_accout)
    {
       if(event->type() == QEvent::FocusIn)     //然后再判断控件的具体事件 (这里指获得焦点事件)
       {
           QPalette p = QPalette();
           //p.setColor(QPalette::Window, Qt::lightGray);  //改变控件背景色
           //p.setColor(QPalette::WindowText, Qt::blue);   //改变控件字体颜色
           p.setColor(QPalette::Base,Qt::blue);
           ui->le_accout->setPalette(p);
       }
       else if (event->type()==QEvent::FocusOut)    // 这里指控件的失去焦点事件
       {
           QPalette p = QPalette();
           p.setColor(QPalette::Base,Qt::white);
           ui->le_accout->setPalette(p);
       }
    }
    if(watched == ui->le_passwd)
    {
         if(event->type() == QEvent::FocusIn)
         {
            QPalette p = QPalette();
            p.setColor(QPalette::Base,Qt::blue);
            ui->le_passwd->setPalette(p);
         }
        else if(event->type()==QEvent::FocusOut)
        {
            QPalette p = QPalette();
            p.setColor(QPalette::Base,Qt::white);
            ui->le_passwd->setPalette(p);
        }
    }
    if(watched == ui->le_passwd2)
    {
        if(event->type() == QEvent::FocusIn)
        {
           QPalette p = QPalette();
           p.setColor(QPalette::Base,Qt::blue);
           ui->le_passwd2->setPalette(p);
        }
       else if(event->type()==QEvent::FocusOut)
       {
           QPalette p = QPalette();
           p.setColor(QPalette::Base,Qt::white);
           ui->le_passwd2->setPalette(p);
       }
    }
    if(watched == ui->le_coder)
    {
        if(event->type() == QEvent::FocusIn)
        {
           QPalette p = QPalette();
           p.setColor(QPalette::Base,Qt::blue);
           ui->le_coder->setPalette(p);
        }
       else if(event->type()==QEvent::FocusOut)
       {
           QPalette p = QPalette();
           p.setColor(QPalette::Base,Qt::white);
           ui->le_coder->setPalette(p);
       }
    }
    return false;
}

//鼠标点击每个lineedit进行的判断操作
void Register::myLineEditClicked(MyLineEdit* line)
{
    if(line == ui->le_accout)
    {
        ui->lab_acc->clear();
    }else if(line == ui->le_passwd)
    {
        ui->lab_pwd->clear();
        QString myAccount = ui->le_accout->text();
        if(myAccount.isEmpty())
        {
            ui->lab_acc->setText("账号不能为空");
        }else
        {
            emit sigCnki(myAccount);
        }
    }else if(line == ui->le_passwd2)
    {
        ui->lab_pwd2->clear();
        QString myPasswd = ui->le_passwd->text();
        QString myAccount = ui->le_accout->text();
        if(myAccount.isEmpty())
        {
            ui->lab_acc->setText("账号不能为空");
        }
        if(myPasswd.isEmpty())
        {
            ui->lab_pwd->setText("密码不能为空");
        }
    }else if(line == ui->le_coder)
    {
        ui->lab_coder->clear();
        QString myPasswd = ui->le_passwd->text();
        QString myAccount = ui->le_accout->text();
        QString myPasswd2 = ui->le_passwd2->text();
        if(myAccount.isEmpty())
        {
            ui->lab_acc->setText("账号不能为空");
        }
        if(myPasswd.isEmpty())
        {
            ui->lab_pwd->setText("密码不能为空");
        }
        if(myPasswd2.isEmpty())
        {
            ui->lab_pwd2->setText("请再次输入密码");
        }else if(myPasswd != myPasswd2)
        {
            ui->lab_pwd2->setText("两次密码输入不一致");
        }

    }
}

//接收查重结果显示的槽
void Register::registerCnkiSlot(QString &message)
{
    ui->lab_acc->setText(message);
}

//换一张验证码
void Register::on_pushButton_clicked()
{
    m_pCodeArea->replaceCodePic();
}

void Register::on_ch_Box_clicked()
{
    if(ui->ch_Box->isChecked())
    {
        ui->btn_register->setEnabled(true);
    }else
        ui->btn_register->setEnabled(false);
}
