#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}
class QLineEdit;
class QDialog;
class MySyntaxHighlighter;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTextFrame();   //遍历文档框架
    void showTextBlock();   //遍历所有文本块
    void setTextfont(bool checked);  //设置字体
    void insertTable();
    void insertList();
    void insertImage();
    void textfind();
    void findNext();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineedit;
    QDialog *findDialog;
    MySyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H
