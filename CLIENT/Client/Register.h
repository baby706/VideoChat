#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "MyLineEdit.h"
#include "codearea.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

signals:
    void sigRegister(QString &,QString &);
    void sigCnki(QString &);
private slots:
    void on_btn_register_clicked();
    void myLineEditClicked(MyLineEdit* );
    void registerCnkiSlot(QString &);

    void on_pushButton_clicked();

    void on_ch_Box_clicked();

protected:
    bool virtual eventFilter(QObject *, QEvent *);

private:
    CodeArea *m_pCodeArea = nullptr;		// 验证码绘制组件
    Ui::Register *ui;
};

#endif // REGISTER_H
