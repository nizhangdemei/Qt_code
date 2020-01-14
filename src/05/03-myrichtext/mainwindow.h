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
    void showTextFrame();   //�����ĵ����
    void showTextBlock();   //���������ı���
    void setTextfont(bool checked);  //��������
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
