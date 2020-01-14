#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QProgressDialog>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);




}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //静态创建
//    QColor color  = QColorDialog::getColor(Qt::red,this,(QString::fromLocal8Bit("颜色对话框")),QColorDialog::ShowAlphaChannel);
//    qDebug() << "color" << color;
    //动态创建
    QColorDialog dialog(Qt::blue,this);
    dialog.setWindowTitle(QString::fromLocal8Bit("颜色"));
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor col = dialog.currentColor();
    qDebug() << col << endl;
}

void MyWidget::on_pushButton_2_clicked()
{
    //只能选择单个文件 。多个文件使用getOpenFileNames ,用QStringList 接受多个文件
    QString filename = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("文件对话框"),
                                 "",QString::fromLocal8Bit("图片文件（*.png *.jpg );;源文件(*.cpp *.h)"));
    qDebug() << "filename" <<  filename <<endl;
}


void MyWidget::on_pushButton_font_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
        ui->pushButton_font->setFont(font);
    else {
        qDebug() << QString::fromLocal8Bit("没有选择字体") << endl;
    }
}

void MyWidget::on_pushButton_4_clicked()
{/*//////////////////////////////静态函数/////////////////////////*/
    //获取字符串
    bool ok;
    QString string = QInputDialog::getText(this,QString::fromLocal8Bit("输入字符串对话框"),QString::fromLocal8Bit("用户名"),QLineEdit::Normal,"admin",&ok);
    if(ok)
    {
        qDebug() << string << endl;
    }
    //获取整数
    int value = QInputDialog::getInt(this,QString::fromLocal8Bit("整数对话框"),QString::fromLocal8Bit("整数-1000 -1000 "),100,-1000,1000,10,&ok);
    if(ok)
    {
        qDebug() << value << endl;
    }
    //获取浮点数
    double value1 = QInputDialog::getDouble(this,QString::fromLocal8Bit("浮点数"),QString::fromLocal8Bit("输入浮点数范围"),12.10,-12.20,15.99,1,&ok);
    if(ok)
    {
        qDebug() << value1 << endl;
    }
    //条目对话框       //true表示条目可以被更改
    QStringList items;
    items << QString::fromLocal8Bit("条目1") << QString::fromLocal8Bit("条目2");
    QString item = QInputDialog::getItem(this,QString::fromLocal8Bit("输入条目对话框"),QString::fromLocal8Bit("选择一个条目"),items,0,true,&ok);
    if(ok)
    {
        qDebug() << item <<endl;
    }


}

void MyWidget::on_pushButton_5_clicked()
{
    //问题对话框
   int ret =  QMessageBox::question(this,QString::fromLocal8Bit("问题对话框"),QString::fromLocal8Bit("你了解Qt吗"),QMessageBox::Yes,QMessageBox::No);
   if(ret == QMessageBox::Yes)
   {
       qDebug() << "question" << endl;
   }
   //提示对话框
   int ret1 = QMessageBox::information(this,QString::fromLocal8Bit("提示对话框"),QString::fromLocal8Bit("这是Qt书籍"),QMessageBox::Ok);
   if(ret1 == QMessageBox::Ok)
   {
       qDebug() << "提示" << endl;
   }
   //警告对话框
   int ret2 = QMessageBox::warning(this,QString::fromLocal8Bit("警告对话框"),QString::fromLocal8Bit("这是一个警告"),QMessageBox::Abort);
   if(ret2 == QMessageBox::Abort)
           qDebug() << "这是一个警告" << endl;
    //错误对话框
   QMessageBox::critical(this,QString::fromLocal8Bit("严重错误"),QString::fromLocal8Bit("发生严重错误"),QMessageBox::YesAll);
   if(ret2 == QMessageBox::YesAll)
   {
     qDebug() << "严重错误" <<endl;
    }
    //关于对话框
     QMessageBox::about(this,QString::fromLocal8Bit("关于对话框"),QString::fromLocal8Bit("致力于Qt工作"));

}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(QString::fromLocal8Bit("复制进度"),QString::fromLocal8Bit("取消"),0,100000,this);
    dialog.setWindowTitle(QString::fromLocal8Bit("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);   //设置为模态对话框
    dialog.show();

    for(int i=0;i < 100000;i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();  //防止窗口冻结
        if(dialog.wasCanceled())
        {
            break;
        }
    }
    dialog.setValue(100000);               //放到循环结束用于显示100%
    qDebug() << QString::fromLocal8Bit("复制结束");

}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(QString::fromLocal8Bit("错误信息对话框"));
    errordlg->showMessage(QString::fromLocal8Bit("这里是出错信息"));   //非模态信息
}
//向导对话框  QWizard 框架
void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(QString::fromLocal8Bit("向导对话框"));
    wizard.addPage(creatPage1());
    wizard.addPage(creatPage2());
    wizard.addPage(creatPage3());
    wizard.exec();
}

QWizardPage *MyWidget::creatPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("介绍"));
    return page;
}

QWizardPage *MyWidget::creatPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("用户选择信息"));
    return page;
}

QWizardPage *MyWidget::creatPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("结束"));
    return page;
}
