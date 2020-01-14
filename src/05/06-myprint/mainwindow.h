#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPrinter;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void doPrint();
    void doPrintPreview();
    void printPreview(QPrinter *printer);
    void createPdf();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
