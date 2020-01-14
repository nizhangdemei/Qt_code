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
    label->setAttribute(Qt::WA_DeleteOnClose);  //窗口关闭自动销毁
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //获取图片，将鼠标指针所在位置的部件强制转换为QLabel类型
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(child->inherits("QLabel"))
    {
        return;
    }
    QPixmap pixmap = *child->pixmap();
    //自定义MIME类型
    QByteArray itemData;  //创建字节数组 ,创建数据流
    QDataStream datastream(&itemData,QIODevice::WriteOnly);
    //将图片信息，位置信息输入到字节流
    datastream << pixmap << QPoint(event->pos() - child->pos());
    //将数据放入QMimeData中
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png",itemData);
    //将 QMimeData数据放入QDrag中
    QDrag *drag = new QDrag(this);  //用来移动数据
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos()-child->pos()); //拖动时鼠标指针位置不变
    //给原图片添加阴影
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    //在图片的外接矩形中添加一层透明的淡黑色形成阴影效果
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    child->setPixmap(tempPixmap);
    //执行拖放操作
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
    //如果是自定义mime类型，则进行移动操作
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
        //使用数据流读到变量中
        dataStream >> pixmap >> offset;
        //新建标签
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        //图片移动到放下的位置
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
