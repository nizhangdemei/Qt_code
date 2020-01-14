#ifndef HELLO_H
#define HELLO_H

#include <QDialog>

class hello : public QDialog
{
    Q_OBJECT

public:
    hello(QWidget *parent = 0);
    ~hello();
};

#endif // HELLO_H
