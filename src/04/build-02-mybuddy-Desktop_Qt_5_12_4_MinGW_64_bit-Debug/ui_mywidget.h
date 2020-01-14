/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        label = new QLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 54, 12));
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 61, 16));
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 150, 81, 16));
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 200, 81, 16));
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 70, 80, 20));
        checkBox = new QCheckBox(MyWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(160, 110, 73, 18));
        lineEdit = new QLineEdit(MyWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 150, 113, 20));
        spinBox = new QSpinBox(MyWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(170, 200, 46, 22));
#ifndef QT_NO_SHORTCUT
        label->setBuddy(pushButton);
        label_2->setBuddy(checkBox);
        label_3->setBuddy(lineEdit);
        label_4->setBuddy(spinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        label->setText(QApplication::translate("MyWidget", "&button", nullptr));
        label_2->setText(QApplication::translate("MyWidget", "C&heckBox", nullptr));
        label_3->setText(QApplication::translate("MyWidget", "\350\241\214\347\274\226\350\276\221\345\231\250(&L)", nullptr));
        label_4->setText(QApplication::translate("MyWidget", "\346\225\260\345\255\227\351\200\211\346\213\251\346\241\206(&N)", nullptr));
        pushButton->setText(QApplication::translate("MyWidget", "PushButton", nullptr));
        checkBox->setText(QApplication::translate("MyWidget", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
