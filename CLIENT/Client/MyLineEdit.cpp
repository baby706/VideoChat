#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent)
    :QLineEdit(parent)
{

}

void MyLineEdit::mousePressEvent(QMouseEvent *)
{
    emit LineEditClicked(this);
}
