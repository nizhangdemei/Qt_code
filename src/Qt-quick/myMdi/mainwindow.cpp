#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include "mdichild.h"
#include <QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this);
    actionSeparator->setSeparator(true);
    updateMenus();

    connect(ui->mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::updateMenus);\


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMenus()
{
    //�����Ƿ��л���������ø������Ƿ����
    bool hasMdiChild = (this->activeMdiChild()!= nullptr);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAS->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPreview->setEnabled(hasMdiChild);
    //���ü�����Ƿ���ʾ
    actionSeparator->setVisible(hasMdiChild);
    //�л���ڲ����б�ѡ����ı������и��Ʋſ���
    bool hasSelection = (activeMdiChild() && activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);
    //�л���ڲ����ĵ��г�������������������
    ui->actionUndo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());
    //�л���ڲ����ĵ��лָ�����ʱ�ָ���������
    ui->actionRedo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isRedoAvailable());


}

void MainWindow::on_actionNew_triggered()
{

}

MdiChild *MainWindow::activeMdiChild()
{
    if(QMdiSubWindow *activeSubWindos = ui->mdiArea->activeSubWindow())
    {
        return qobject_cast<MdiChild *>(activeSubWindos->widget());
    }
    return nullptr;

}

void MainWindow::on_actionOpen_triggered()
{

}
