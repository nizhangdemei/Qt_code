#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *action_print = new QAction("print",this);
    QAction *action_printPreview = new QAction("Pr_Preview",this);
    QAction *action_pdf = new QAction("make_pdf",this);
    connect(action_print,&QAction::triggered,this,&MainWindow::doPrint);
    connect(action_printPreview,&QAction::triggered,this,&MainWindow::doPrintPreview);
    connect(action_pdf,&QAction::triggered,this,&MainWindow::createPdf);
    ui->mainToolBar->addAction(action_print);
    ui->mainToolBar->addAction(action_printPreview);
    ui->mainToolBar->addAction(action_pdf);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::doPrint()
{
    //创建打印机对象
    QPrinter printer;
    QPrintDialog dlg(&printer,this);
    //如果有选中区域，则打印选中区域
    if(ui->textEdit->textCursor().hasSelection())
    {
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
    if(dlg.exec() == QDialog::Accepted)
    {
        ui->textEdit->print(&printer);
    }

}

void MainWindow::doPrintPreview()
{
    QPrinter printer;
    QPrintPreviewDialog preview(&printer,this);
    connect(&preview,&QPrintPreviewDialog::paintRequested,this,&MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter *printer)
{
    ui->textEdit->print(printer);
}

void MainWindow::createPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this,"make_pdf",QString(),"*.pdf");
    if(!fileName.isEmpty())
    {
        if(QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append("*.pdf");
        }
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        ui->textEdit->print(&printer);
    }
}
