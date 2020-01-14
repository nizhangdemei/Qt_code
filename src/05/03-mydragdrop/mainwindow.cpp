#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//拖动进入事件
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
   if(event->mimeData()->hasUrls())   //数据中是否包含url
   {
       event->acceptProposedAction();   //是则接受动作
   }
   else {
       event->ignore();           //忽略
   }
}
//放下事件
void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();    //获取MIME数据
    if(mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();      //获取url列表
        QString fileName = urlList.at(0).toLocalFile();
        if(!fileName.isEmpty())
        {
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly))
                return;
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }
}
