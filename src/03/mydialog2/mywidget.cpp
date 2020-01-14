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
    //��̬����
//    QColor color  = QColorDialog::getColor(Qt::red,this,(QString::fromLocal8Bit("��ɫ�Ի���")),QColorDialog::ShowAlphaChannel);
//    qDebug() << "color" << color;
    //��̬����
    QColorDialog dialog(Qt::blue,this);
    dialog.setWindowTitle(QString::fromLocal8Bit("��ɫ"));
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor col = dialog.currentColor();
    qDebug() << col << endl;
}

void MyWidget::on_pushButton_2_clicked()
{
    //ֻ��ѡ�񵥸��ļ� ������ļ�ʹ��getOpenFileNames ,��QStringList ���ܶ���ļ�
    QString filename = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("�ļ��Ի���"),
                                 "",QString::fromLocal8Bit("ͼƬ�ļ���*.png *.jpg );;Դ�ļ�(*.cpp *.h)"));
    qDebug() << "filename" <<  filename <<endl;
}


void MyWidget::on_pushButton_font_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
        ui->pushButton_font->setFont(font);
    else {
        qDebug() << QString::fromLocal8Bit("û��ѡ������") << endl;
    }
}

void MyWidget::on_pushButton_4_clicked()
{/*//////////////////////////////��̬����/////////////////////////*/
    //��ȡ�ַ���
    bool ok;
    QString string = QInputDialog::getText(this,QString::fromLocal8Bit("�����ַ����Ի���"),QString::fromLocal8Bit("�û���"),QLineEdit::Normal,"admin",&ok);
    if(ok)
    {
        qDebug() << string << endl;
    }
    //��ȡ����
    int value = QInputDialog::getInt(this,QString::fromLocal8Bit("�����Ի���"),QString::fromLocal8Bit("����-1000 -1000 "),100,-1000,1000,10,&ok);
    if(ok)
    {
        qDebug() << value << endl;
    }
    //��ȡ������
    double value1 = QInputDialog::getDouble(this,QString::fromLocal8Bit("������"),QString::fromLocal8Bit("���븡������Χ"),12.10,-12.20,15.99,1,&ok);
    if(ok)
    {
        qDebug() << value1 << endl;
    }
    //��Ŀ�Ի���       //true��ʾ��Ŀ���Ա�����
    QStringList items;
    items << QString::fromLocal8Bit("��Ŀ1") << QString::fromLocal8Bit("��Ŀ2");
    QString item = QInputDialog::getItem(this,QString::fromLocal8Bit("������Ŀ�Ի���"),QString::fromLocal8Bit("ѡ��һ����Ŀ"),items,0,true,&ok);
    if(ok)
    {
        qDebug() << item <<endl;
    }


}

void MyWidget::on_pushButton_5_clicked()
{
    //����Ի���
   int ret =  QMessageBox::question(this,QString::fromLocal8Bit("����Ի���"),QString::fromLocal8Bit("���˽�Qt��"),QMessageBox::Yes,QMessageBox::No);
   if(ret == QMessageBox::Yes)
   {
       qDebug() << "question" << endl;
   }
   //��ʾ�Ի���
   int ret1 = QMessageBox::information(this,QString::fromLocal8Bit("��ʾ�Ի���"),QString::fromLocal8Bit("����Qt�鼮"),QMessageBox::Ok);
   if(ret1 == QMessageBox::Ok)
   {
       qDebug() << "��ʾ" << endl;
   }
   //����Ի���
   int ret2 = QMessageBox::warning(this,QString::fromLocal8Bit("����Ի���"),QString::fromLocal8Bit("����һ������"),QMessageBox::Abort);
   if(ret2 == QMessageBox::Abort)
           qDebug() << "����һ������" << endl;
    //����Ի���
   QMessageBox::critical(this,QString::fromLocal8Bit("���ش���"),QString::fromLocal8Bit("�������ش���"),QMessageBox::YesAll);
   if(ret2 == QMessageBox::YesAll)
   {
     qDebug() << "���ش���" <<endl;
    }
    //���ڶԻ���
     QMessageBox::about(this,QString::fromLocal8Bit("���ڶԻ���"),QString::fromLocal8Bit("������Qt����"));

}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(QString::fromLocal8Bit("���ƽ���"),QString::fromLocal8Bit("ȡ��"),0,100000,this);
    dialog.setWindowTitle(QString::fromLocal8Bit("���ȶԻ���"));
    dialog.setWindowModality(Qt::WindowModal);   //����Ϊģ̬�Ի���
    dialog.show();

    for(int i=0;i < 100000;i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();  //��ֹ���ڶ���
        if(dialog.wasCanceled())
        {
            break;
        }
    }
    dialog.setValue(100000);               //�ŵ�ѭ������������ʾ100%
    qDebug() << QString::fromLocal8Bit("���ƽ���");

}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(QString::fromLocal8Bit("������Ϣ�Ի���"));
    errordlg->showMessage(QString::fromLocal8Bit("�����ǳ�����Ϣ"));   //��ģ̬��Ϣ
}
//�򵼶Ի���  QWizard ���
void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(QString::fromLocal8Bit("�򵼶Ի���"));
    wizard.addPage(creatPage1());
    wizard.addPage(creatPage2());
    wizard.addPage(creatPage3());
    wizard.exec();
}

QWizardPage *MyWidget::creatPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("����"));
    return page;
}

QWizardPage *MyWidget::creatPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("�û�ѡ����Ϣ"));
    return page;
}

QWizardPage *MyWidget::creatPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(QString::fromLocal8Bit("����"));
    return page;
}
