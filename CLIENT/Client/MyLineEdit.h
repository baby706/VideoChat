#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit MyLineEdit(QWidget *parent = 0);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
signals:
    void LineEditClicked(MyLineEdit* );
};

#endif // MYLINEEDIT_H
