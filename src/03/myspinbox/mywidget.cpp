#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //设置时间为系统时间
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    //设置时间显示格式
    ui->dateTimeEdit->setDisplayFormat(QString::fromLocal8Bit("yyyy 年 MM 月 dd 日 ddd HH 时 mm 分 ss 秒"));

}

MyWidget::~MyWidget()
{
    delete ui;
}
