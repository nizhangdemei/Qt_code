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
    //�����ڹر�ʱ���ٸ������
    this->setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;    // ����Ƿ񱻱������Ĭ��Ϊtrue


}

void MdiChild::newFile()    // �½��ļ�
{
    //ʹ�þ�̬���� �༭���ڱ��
    static int sequenceNum = 1;
    //�½��ĵ�δ������
    isUntitled = true;
    //��ǰ�ĵ�����
    curFile = QString::fromLocal8Bit("δ�����ĵ� %1").arg(sequenceNum++);
    //���ô��ڱ���,�ĵ��ڸ��ĺ���ʾ* ��
    setWindowTitle(curFile + "[*]" + QString::fromLocal8Bit("--�ĵ��༭��"));
    //�ĵ�������ʱ�����ź�
    connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);



}
//�����ļ�
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
     //�����ı���
     QTextStream in(&file);
     //�������״̬Ϊ�ȴ�״̬
     QApplication::setOverrideCursor(Qt::WaitCursor);
     //��ȡ�ı�ȫ������
     this->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();
     //���õ�ǰ�ļ�
     setCurrentFile(fileName);
     connect(document(),&QTextDocument::contentsChanged,this,&MdiChild::documentWasModified);
     return true;
}

bool MdiChild::save()
{
    //����ļ�δ���������ִ�����Ϊ����������ֱ�ӱ����ļ�
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
    //��ȡ�ļ�·����Ϊ�շ���false,���򱣴��ļ�
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
    //�Ƿ���Ҫ���棬maybesave����true,��رմ��ڣ���������¼�
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
    //����ĵ������Ĺ�
    if(document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle("edit");
        box.setText(QString::fromLocal8Bit("�Ƿ񱣴���ĵ� %1 ���޸�").arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        //��Ӱ�ťQMessageBox::YesRole ������ť����Ϊ
        QPushButton *yesBtn =  box.addButton("Yes(&Y)",QMessageBox::YesRole);
        box.addButton("No(&N)",QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton("Cancel",QMessageBox::RejectRole);
        box.exec();
        if(box.clickedButton() == yesBtn)
            return  save();  //���б������
        else if(box.clickedButton() == cancelBtn)
            return false;
    }
    //û�������������true
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
   //canonicalFilePath() ����ȥ��·���еķ������ӣ� ��.���� ��..�� ����
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    //���ô��ڱ���
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

}
