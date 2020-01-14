#ifndef MDICHILD_H
#define MDICHILD_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
class QTextEdit;
class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = nullptr);
    //�½�����
    void newFile();
    //���ļ�(load)
    bool loadFile(const QString &fileName);
    //�������
    bool save();
    //���Ϊ����
    bool savaAs();
    //�����ļ���
    bool saveFile(const QString &fileName);
    //��ȡ�ļ���
    QString userFriendlyCurrentFile();
    //���ص�ǰ�ļ�·��
    QString currentFile();


protected:
    //�ر��¼�
    void closeEvent(QCloseEvent *event);


signals:

public slots:
    //�ĵ�������ʱ��������ʾ����״̬��־
    void documentWasModified();
private:
    //�Ƿ���Ҫ����
    bool maybeSave();
    //���õ�ǰ�ļ�
    void setCurrentFile(const QString &fileName);
    //���浱ǰ�ļ�·��
    QString curFile;
    //��Ϊ��ǰ�ļ��Ƿ񱻱��浽Ӳ���ϵı�־
    bool isUntitled;



};



#endif // MDICHILD_H
