#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
//    QHBoxLayout *layout = new QHBoxLayout(this);
//    layout->addWidget(ui->fontComboBox,2);
//    layout->addWidget(ui->textEdit,1);
//    layout->setSpacing(1);
//    layout->setContentsMargins(0,0,50,100);
//    setLayout(layout);

//    QGridLayout * layout = new QGridLayout;   //会重新定义自己的父对象，不需要指定
//    layout->addWidget(ui->fontComboBox,0,0,1,2);
//    layout->addWidget(ui->pushButton,0,2,1,1);
//    layout->addWidget(ui->textEdit,1,0,1,3);

//    setLayout(layout);
    ui->textEdit->hide();

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_toggled(bool checked)
{
    qDebug() << checked << endl;
    ui->textEdit->setVisible(checked);
    if(checked)
    {
        ui->pushButton->setText(QString::fromLocal8Bit("隐藏可扩展窗口"));
    }
    else {
        ui->pushButton->setText(QString::fromLocal8Bit("显示可扩展窗口"));
    }
}
