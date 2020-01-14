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
//�϶������¼�
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
   if(event->mimeData()->hasUrls())   //�������Ƿ����url
   {
       event->acceptProposedAction();   //������ܶ���
   }
   else {
       event->ignore();           //����
   }
}
//�����¼�
void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();    //��ȡMIME����
    if(mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();      //��ȡurl�б�
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
