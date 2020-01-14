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
//���ò˵�
    QMenu *editMenu = ui->menuBar->addMenu(QString::fromLocal8Bit("�༭(&E)"));
    QAction *action_Open = editMenu->addAction(QIcon(":/image/3.jpg"),QString::fromLocal8Bit("���ļ�"));
    editMenu->addSeparator();
    QAction *action_Close = editMenu->addAction(QIcon(":/image/8.jpg"),QString::fromLocal8Bit("�ر��ļ�"));

    QActionGroup * group = new QActionGroup(this);
    QAction * action_L = group->addAction(QString::fromLocal8Bit("�����"));
    action_L->setCheckable(true);
    QAction *action_R =  group->addAction(QString::fromLocal8Bit("�Ҷ���"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(QString::fromLocal8Bit("����"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
//���ù�����
    QToolButton * toolbutton = new QToolButton(this);
    toolbutton->setText("color");
    QMenu * colorMenu = new QMenu(this);
    colorMenu->addAction("red");
    colorMenu->addAction("green");
    toolbutton->setMenu(colorMenu);
    toolbutton->setPopupMode(QToolButton::MenuButtonPopup); //���õ���ģʽ ��С��ͷ������
    ui->mainToolBar->addWidget(toolbutton);
    QSpinBox * spinBox= new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

//״̬��
    //��ʾ��ʱ��Ϣ
    ui->statusBar->showMessage("welcome to edit ",2000);
    //������ǩ�����ò���ʾ��Ϣ��Ȼ���������ò�������ʽ��ӵ�״̬��
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
    //�½��ı��༭������
    QTextEdit * edit = new QTextEdit(this);
    QMdiSubWindow * child =  ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle("duowendang bianjiqi");
    child->show();
}

void MyConsole::on_actionxianshiDock_triggered()
{
    ui->dockWidget->show();
}
