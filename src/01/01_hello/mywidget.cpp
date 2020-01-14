#include "mywidget.h"
#include "ui_mywidget.h"
#include "mydialog.h"
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    this->close();
    MyDialog dia ;
    //如果按下会显示主界面 ，
    //
    if(dia.exec() == QDialog::Accepted)
    {
        dia.show();

    }

}
