#include "hello.h"
#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QWidget>
#include <QDebug>
#include "mydialog.h"
#include "mywidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ////////////////////////第二章////////////////////
//    QDialog dia;
//    dia.resize(800,600);
//    QLabel lab(&dia);
//    lab.move(120,120);
//    lab.setText(QString::fromLocal8Bit("hello,world! 你好Qt!"));
//    dia.show();
       /////////////////////第三章//////////////////////
//      QWidget *widget  =new QWidget(nullptr,Qt::Dialog | Qt::FramelessWindowHint);
//      widget->setWindowState(Qt::WindowActive);
//      widget->setWindowTitle(QString::fromLocal8Bit("This is widget "));

//      QLabel *label = new QLabel(nullptr,Qt::SplashScreen | Qt::WindowStaysOnTopHint);
//      label->setWindowTitle("this is label");
//      label->setText(QString::fromLocal8Bit("我是一个窗口"));
//      label->resize(180,20);

//      QLabel * label1 = new QLabel(widget);
//      label1->setText(QString::fromLocal8Bit("wiget 子部件"));
//      label1->resize(250,20);

//      label->show();
//      widget->show();
//      // 窗口等待析构完后释放
//      int ret =a.exec();
//      delete label;
//      delete widget;
//      return ret;
      //QWidget////////////
//        QWidget  wideget1;
//        wideget1.resize(400,300);
//        wideget1.move(200,300);
//        wideget1.show();
//        int x = wideget1.x();
//        int y = wideget1.y();
//        QRect geomery = wideget1.geometry();
//        QRect frame = wideget1.frameGeometry();
//        qDebug() << x << endl;
//        qDebug() << y << endl;
//        qDebug() << geomery << endl;
//        qDebug() << frame  << endl;

        MyWidget widget1;
        MyDialog dia;
        if(dia.exec() == QDialog::Accepted)
        {
            widget1.show();
            return a.exec();
        }
        else {
            return 0;
        }


    //    hello w;
    //    w.show();
   // return  a.exec();
}
