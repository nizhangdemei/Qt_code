#include "myconsole.h"
#include "ui_myconsole.h"
#include <QToolButton>
#include <QSpinBox>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QLabel>
#include <QTextEdit>
MyConsole::MyConsole(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyConsole)
{
    ui->setupUi(this);
//设置菜单
    QMenu *editMenu = ui->menuBar->addMenu(QString::fromLocal8Bit("编辑(&E)"));
    QAction *action_Open = editMenu->addAction(QIcon(":/image/3.jpg"),QString::fromLocal8Bit("打开文件"));
    editMenu->addSeparator();
    QAction *action_Close = editMenu->addAction(QIcon(":/image/8.jpg"),QString::fromLocal8Bit("关闭文件"));

    QActionGroup * group = new QActionGroup(this);
    QAction * action_L = group->addAction(QString::fromLocal8Bit("左对齐"));
    action_L->setCheckable(true);
    QAction *action_R =  group->addAction(QString::fromLocal8Bit("右对齐"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(QString::fromLocal8Bit("居中"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
//设置工具栏
    QToolButton * toolbutton = new QToolButton(this);
    toolbutton->setText("color");
    QMenu * colorMenu = new QMenu(this);
    colorMenu->addAction("red");
    colorMenu->addAction("green");
    toolbutton->setMenu(colorMenu);
    toolbutton->setPopupMode(QToolButton::MenuButtonPopup); //设置弹出模式 （小箭头下拉）
    ui->mainToolBar->addWidget(toolbutton);
    QSpinBox * spinBox= new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

//状态栏
    //显示临时消息
    ui->statusBar->showMessage("welcome to edit ",2000);
    //创建标签，设置并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.google.com");
    ui->statusBar->addPermanentWidget(permanent);

}


MyConsole::~MyConsole()
{
    delete ui;
}

void MyConsole::on_action_new_triggered()
{
    //新建文本编辑器部件
    QTextEdit * edit = new QTextEdit(this);
    QMdiSubWindow * child =  ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle("duowendang bianjiqi");
    child->show();
}

void MyConsole::on_actionxianshiDock_triggered()
{
    ui->dockWidget->show();
}
