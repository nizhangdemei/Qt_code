#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    /////第三十五天QFile///////////////////
    QFile file("H:\\123.txt");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        qDebug() << "open file failed"<<endl;
        return ;
    }
    else {
        while(!file.atEnd())
        {
            //解决读取本地文件中文乱码问题
            QByteArray array = file.readLine();
            QString string = QString::fromLocal8Bit(array.data());
            qDebug() << string;
        }
    }
    QFileInfo info(file);
    qDebug() << info.isDir();   //是否是目录
    qDebug() << info.isExecutable(); //是否是可执行文件
    qDebug() << info.baseName();  //获取文件名
    qDebug() << info.completeBaseName();
    qDebug() << info.suffix();    //获取文件后缀名
    qDebug() << info.completeSuffix();

}

mainWindow::~mainWindow()
{
    delete ui;
}
