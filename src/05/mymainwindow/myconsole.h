#ifndef MYCONSOLE_H
#define MYCONSOLE_H

#include <QMainWindow>

namespace Ui {
class MyConsole;
}

class MyConsole : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyConsole(QWidget *parent = nullptr);
    ~MyConsole();

private slots:
    void on_action_new_triggered();

    void on_actionxianshiDock_triggered();

private:
    Ui::MyConsole *ui;
};

#endif // MYCONSOLE_H
