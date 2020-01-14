/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAS;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionTile;
    QAction *actionCascade;
    QAction *actionNext;
    QAction *actionPreview;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_W;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(469, 306);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pic/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSaveAS = new QAction(MainWindow);
        actionSaveAS->setObjectName(QString::fromUtf8("actionSaveAS"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pic/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAS->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/pic/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/pic/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/pic/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/pic/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/pic/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/pic/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon9);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionCloseAll = new QAction(MainWindow);
        actionCloseAll->setObjectName(QString::fromUtf8("actionCloseAll"));
        actionTile = new QAction(MainWindow);
        actionTile->setObjectName(QString::fromUtf8("actionTile"));
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName(QString::fromUtf8("actionCascade"));
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/pic/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon10);
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QString::fromUtf8("actionPreview"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/pic/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreview->setIcon(icon11);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/pic/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon12);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 469, 22));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addSeparator();
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addSeparator();
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAS);
        menu_F->addSeparator();
        menu_F->addAction(actionExit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addSeparator();
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_W->addAction(actionClose);
        menu_W->addAction(actionCloseAll);
        menu_W->addSeparator();
        menu_W->addAction(actionTile);
        menu_W->addAction(actionCascade);
        menu_W->addSeparator();
        menu_W->addAction(actionNext);
        menu_W->addAction(actionPreview);
        menu_H->addAction(actionAbout);
        menu_H->addAction(actionAboutQt);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSaveAS);
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", nullptr));
        actionNew->setIconText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266(&O)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAS->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveAS->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215(&R)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&O)", nullptr));
        actionCloseAll->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243(&A)", nullptr));
        actionTile->setText(QApplication::translate("MainWindow", "\345\271\263\351\223\272(&T)", nullptr));
        actionCascade->setText(QApplication::translate("MainWindow", "\345\261\202\345\217\240(&C)", nullptr));
        actionNext->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(&X)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNext->setShortcut(QApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_NO_SHORTCUT
        actionPreview->setText(QApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252(&V)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPreview->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Tab", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
        actionAboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt(&Q)", nullptr));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_W->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243(&W)", nullptr));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
