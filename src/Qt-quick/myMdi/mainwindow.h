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
    void updateMenus(); //���²˵�

    private slots:
        void on_actionNew_triggered();
        //���û�Ӵ���
        void setActionSubWindos(QWidget * window);

        void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;
    MdiChild * activeMdiChild();//�����
    QMdiSubWindow *findMdiSubWindos(const QString &fileName);

};

#endif // MAINWINDOW_H
