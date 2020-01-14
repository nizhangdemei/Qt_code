#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void dragEnterEvent(QDragEnterEvent *event);  //�϶������¼�
    void dropEvent(QDropEvent *event);    //�����¼�
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H