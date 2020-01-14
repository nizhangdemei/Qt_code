#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QErrorMessage>
#include <QWizard>
namespace Ui {

class QErrorMessage;

class MyWidget;
}


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_font_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MyWidget *ui;
    QErrorMessage * errordlg;
    QWizardPage *creatPage1();   //向导对话框
    QWizardPage *creatPage2();
    QWizardPage *creatPage3();

};

#endif // MYWIDGET_H
