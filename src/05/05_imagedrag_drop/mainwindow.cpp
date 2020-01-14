#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QMimeData>
#include <QDrag>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,500);
    setAcceptDrops(true);
    QLabel *label = new QLabel(this);
    QPixmap pixmap(":/pic/preview (6).jpg");
    label->setPixmap(pixmap);
    label->resize(pixmap.size());
    label->move(50,50);
    label->setAttribute(Qt::WA_DeleteOnClose);  //���ڹر��Զ�����
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //��ȡͼƬ�������ָ������λ�õĲ���ǿ��ת��ΪQLabel����
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(child->inherits("QLabel"))
    {
        return;
    }
    QPixmap pixmap = *child->pixmap();
    //�Զ���MIME����
    QByteArray itemData;  //�����ֽ����� ,����������
    QDataStream datastream(&itemData,QIODevice::WriteOnly);
    //��ͼƬ��Ϣ��λ����Ϣ���뵽�ֽ���
    datastream << pixmap << QPoint(event->pos() - child->pos());
    //�����ݷ���QMimeData��
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png",itemData);
    //�� QMimeData���ݷ���QDrag��
    QDrag *drag = new QDrag(this);  //�����ƶ�����
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos()-child->pos()); //�϶�ʱ���ָ��λ�ò���
    //��ԭͼƬ�����Ӱ
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    //��ͼƬ����Ӿ��������һ��͸���ĵ���ɫ�γ���ӰЧ��
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    child->setPixmap(tempPixmap);
    //ִ���ϷŲ���
    if(drag->exec(Qt::CopyAction |Qt::MoveAction,Qt::CopyAction) ==
            Qt::MoveAction)
    {
      child->close();
    }
    else {
        child->show();
        child->setPixmap(pixmap);
    }


    
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //������Զ���mime���ͣ�������ƶ�����
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else {
        event->ignore();
    }

}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        QByteArray itemData =event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        //ʹ������������������
        dataStream >> pixmap >> offset;
        //�½���ǩ
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        //ͼƬ�ƶ������µ�λ��
        newLabel->move(event->pos()-offset);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();

    }
    else {
        event->ignore();
    }

}
