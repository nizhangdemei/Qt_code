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
    //新建操作
    void newFile();
    //打开文件(load)
    bool loadFile(const QString &fileName);
    //保存操作
    bool save();
    //另存为操作
    bool savaAs();
    //保存文件名
    bool saveFile(const QString &fileName);
    //提取文件名
    QString userFriendlyCurrentFile();
    //返回当前文件路径
    QString currentFile();


protected:
    //关闭事件
    void closeEvent(QCloseEvent *event);


signals:

public slots:
    //文档被更改时，窗口显示更改状态标志
    void documentWasModified();
private:
    //是否需要保存
    bool maybeSave();
    //设置当前文件
    void setCurrentFile(const QString &fileName);
    //保存当前文件路径
    QString curFile;
    //作为当前文件是否被保存到硬盘上的标志
    bool isUntitled;



};



#endif // MDICHILD_H
