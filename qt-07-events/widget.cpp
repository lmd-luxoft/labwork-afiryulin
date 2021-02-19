#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Mouse Position");
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint position = event->pos();
    findChild<QLineEdit*>("xLineEdit")->setText(QString::number(position.x()));
    findChild<QLineEdit*>("yLineEdit")->setText(QString::number(position.y()));
}
