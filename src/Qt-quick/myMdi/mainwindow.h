#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QMainWindow>
class MdiChild;
namespace Ui {
class MainWindow;
class QMdiSubWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateMenus(); //���²˵�

    private slots:
        void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;
    MdiChild * activeMdiChild();//�����

};

#endif // MAINWINDOW_H
