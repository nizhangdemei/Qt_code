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
    //根据是否有活动窗口来设置各动作是否可用
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
    //设置间隔期是否显示
    actionSeparator->setVisible(hasMdiChild);
    //有活动窗口并且有被选择的文本，剪切复制才可用
    bool hasSelection = (activeMdiChild() && activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);
    //有活动窗口并且文档有撤销操作撤销动作可用
    ui->actionUndo->setEnabled(activeMdiChild() && activeMdiChild()->document()->isUndoAvailable());
    //有活动窗口并且文档有恢复操作时恢复动作可用
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
