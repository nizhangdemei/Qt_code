#include "mdichild.h"
#include <QTextDocument>
#include <QTextEdit>
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>
MdiChild::MdiChild(QWidget *parent) : QTextEdit(parent)
{
    //当窗口关闭时销毁该类对象
    this->setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;    // 检查是否被保存过，默认为true


}

void MdiChild::newFile()    // 新建文件
{
    //使用静态变量 编辑窗口编号
    static int sequenceNum = 1;
    //新建文档未被保存
    isUntitled = true;
    //当前文档命名
    curFile = QString::fromLocal8Bit("未命名文档 %1").arg(sequenceNum++);
    //设置窗口标题,文档在更改后显示* 号
    setWindowTitle(curFile + "[*]" + QString::fromLocal8Bit("--文档编辑器"));
    //文档被更改时发射信号
    connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);



}
//加载文件
bool MdiChild::loadFile(const QString &fileName)
{
     QFile file(fileName);
     if(!file.open(QIODevice::ReadOnly | QFile::Text))
     {
         QMessageBox::warning(this,"edit error",QString::fromLocal8Bit("can't read file:%1 \n %2")
                              .arg(fileName)
                              .arg(file.errorString()));
         return false;
     }
     //建立文本流
     QTextStream in(&file);
     //设置鼠标状态为等待状态
     QApplication::setOverrideCursor(Qt::WaitCursor);
     //读取文本全部内容
     this->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();
     //设置当前文件
     setCurrentFile(fileName);
     connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);
     return true;
}

bool MdiChild::save()
{
    //如果文件未被保存过，执行另存为操作，否则直接保存文件
    if(isUntitled)
    {
        return savaAs();
    }
    else {
        return saveFile(curFile);
    }
}

bool MdiChild::savaAs()
{
    QString fileName =  QFileDialog::getSaveFileName(this,"SavaAS",curFile);
    //获取文件路径，为空返回false,否则保存文件
    if(fileName.isEmpty())
    {
        return false;
    }
    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"edit",QString::fromLocal8Bit("can't write %1\n%2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << this->toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return QFileInfo(curFile).fileName();
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    //是否需要保存，maybesave返回true,则关闭窗口，否则忽略事件
    if(maybeSave())
    {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    //如果文档被更改过
    if(document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle("edit");
        box.setText(QString::fromLocal8Bit("是否保存对文档 %1 的修改").arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        //添加按钮QMessageBox::YesRole 表明按钮的行为
        QPushButton *yesBtn =  box.addButton("Yes(&Y)",QMessageBox::YesRole);
        box.addButton("No(&N)",QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton("Cancel",QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton() == yesBtn)
            return  save();  //进行保存操作
        else if(box.clickedButton() == cancelBtn)
            return false;
    }
    //没被保存过，返回true
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
   //canonicalFilePath() 可以去除路径中的符号链接， “.”和 “..” 符号
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    //设置窗口标题
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

}
