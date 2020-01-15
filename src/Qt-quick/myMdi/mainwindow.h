#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QMdiSubWindow>
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
    void updateMenus(); //更新菜单

    private slots:
        void on_actionNew_triggered();
        //设置活动子窗口
        void setActionSubWindos(QWidget * window);

        void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;
    MdiChild * activeMdiChild();//活动窗口
    QMdiSubWindow *findMdiSubWindos(const QString &fileName);

};

#endif // MAINWINDOW_H
