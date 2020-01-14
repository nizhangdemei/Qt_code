/********************************************************************************
** Form generated from reading UI file 'myconsole.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCONSOLE_H
#define UI_MYCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyConsole
{
public:
    QAction *action_new;
    QAction *action_save;
    QAction *actionxianshiDock;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MyConsole)
    {
        if (MyConsole->objectName().isEmpty())
            MyConsole->setObjectName(QString::fromUtf8("MyConsole"));
        MyConsole->resize(454, 369);
        action_new = new QAction(MyConsole);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/5.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_new->setIcon(icon);
        action_save = new QAction(MyConsole);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_save->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/10.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_save->setIcon(icon1);
        actionxianshiDock = new QAction(MyConsole);
        actionxianshiDock->setObjectName(QString::fromUtf8("actionxianshiDock"));
        centralWidget = new QWidget(MyConsole);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MyConsole->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyConsole);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MyConsole->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyConsole);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyConsole->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyConsole);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyConsole->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MyConsole);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        fontComboBox = new QFontComboBox(dockWidgetContents_2);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(190, 0, 216, 22));
        pushButton = new QPushButton(dockWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 0, 80, 20));
        dockWidget->setWidget(dockWidgetContents_2);
        MyConsole->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_new);
        menu->addAction(action_save);
        menu->addAction(actionxianshiDock);

        retranslateUi(MyConsole);

        QMetaObject::connectSlotsByName(MyConsole);
    } // setupUi

    void retranslateUi(QMainWindow *MyConsole)
    {
        MyConsole->setWindowTitle(QApplication::translate("MyConsole", "MyConsole", nullptr));
        action_new->setText(QApplication::translate("MyConsole", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_new->setShortcut(QApplication::translate("MyConsole", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        action_save->setText(QApplication::translate("MyConsole", "\344\277\235\345\255\230\346\226\207\344\273\266(&S)", nullptr));
#ifndef QT_NO_SHORTCUT
        action_save->setShortcut(QApplication::translate("MyConsole", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionxianshiDock->setText(QApplication::translate("MyConsole", "\346\230\276\347\244\272Dock(&P)", nullptr));
        menu->setTitle(QApplication::translate("MyConsole", "\346\226\207\344\273\266(&F)", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MyConsole", "\345\267\245\345\205\267\347\256\261", nullptr));
        pushButton->setText(QApplication::translate("MyConsole", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyConsole: public Ui_MyConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONSOLE_H
