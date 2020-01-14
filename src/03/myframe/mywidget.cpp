#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QMenu>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    //�����ͬ��һ��
    //ui->frame->setFrameStyle(QFrame::Box | QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

//    QFont font;
//    font.setFamily("�����п�");
//    font.setPointSize(20); //��С20
//    font.setBold(true);  //�Ӵ�
//    font.setItalic(true); //б��
//    ui->label->setFont(font);

//    QString string = QString::fromLocal8Bit("����̫������Ҫ����ʡ�ԣ�����");
//    //Qlabel��wordWrap ����ʵ���ı����Զ����У��Զ�ʡ��ʹ��QFontMetrics
//    QString str = ui->label->fontMetrics().elidedText(string,Qt::ElideRight,90);
//    ui->label->setText(str);

    ui->label->setPixmap(QPixmap(":/pic/1.jpg"));

    QMovie *movie = new QMovie(":/pic/2.gif");
    ui->label->setMovie(movie);
    movie->start();

    ui->pushBtn1->setText("&nihao");
    ui->pushBtn2->setText(QString::fromLocal8Bit("������&H��"));
    ui->pushBtn2->setIcon(QIcon(":/pic/5.jpg"));
    ui->pushBtn3->setText("z&oom");

    QMenu *menu = new QMenu(this);
    menu->addAction(QIcon(":/pic/11.jpg"),QString::fromLocal8Bit("�Ŵ�"));
    ui->pushBtn3->setMenu(menu);

}


MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushBtn1_toggled(bool checked)
{
    qDebug() << QString::fromLocal8Bit("��ť�Ƿ���") << checked;
}
