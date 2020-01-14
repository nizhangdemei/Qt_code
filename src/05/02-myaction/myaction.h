#ifndef MYACTION_H
#define MYACTION_H

#include <QObject>
#include <QWidget>
#include <QWidgetAction>
class QLineEdit;
class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyAction(QObject *parent = nullptr);

protected:
    QWidget *createWidget(QWidget *parent);


signals:

    void getText(const QString &string);


public slots:
    void sendText();

private:
    QLineEdit *lineEdit;
};

#endif // MYACTION_H
