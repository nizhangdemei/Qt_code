#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //����ʱ��Ϊϵͳʱ��
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    //����ʱ����ʾ��ʽ
    ui->dateTimeEdit->setDisplayFormat(QString::fromLocal8Bit("yyyy �� MM �� dd �� ddd HH ʱ mm �� ss ��"));

}

MyWidget::~MyWidget()
{
    delete ui;
}
