#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>
#include "mysyntaxhighlighter.h"
#include <QString>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //��ȡ�ĵ�����
    // ��ȡ�����
    //������ܸ�ʽ
    //�߽���ɫ
    //�߽���
    //���ʹ�ø�ʽ
    QTextDocument  *document = ui->textEdit->document();
    QTextFrame *rootFrame = document->rootFrame();
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red);
    format.setBorder(3);
    rootFrame->setFrameFormat(format);

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    frameFormat.setMargin(10);
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(frameFormat);

    QAction *action_textFrame = new QAction("frame",this);
    connect(action_textFrame,&QAction::triggered,this,&MainWindow::showTextFrame);
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction("text block",this);
    connect(action_textBlock,&QAction::triggered,this,&MainWindow::showTextBlock);
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction("font",this);
    action_font->setCheckable(true);  //���ö������Ա�ѡ��
    connect(action_font,&QAction::toggled,this,&MainWindow::setTextfont);
    ui->mainToolBar->addAction(action_font);

    //��� �б� ͼƬ
    QAction *action_textTable = new QAction(QString::fromLocal8Bit("���"),this);
    QAction *action_textList = new QAction(QString::fromLocal8Bit("�б�"),this);
    QAction *action_textImage = new QAction(QString::fromLocal8Bit("ͼƬ"),this);
    connect(action_textTable,&QAction::triggered,this,&MainWindow::insertTable);
    connect(action_textList,&QAction::triggered,this,&MainWindow::insertList);
    connect(action_textImage,&QAction::triggered,this,&MainWindow::insertImage);
    ui->mainToolBar->addAction(action_textTable);
    ui->mainToolBar->addAction(action_textList);
    ui->mainToolBar->addAction(action_textImage);

    //����
    QAction *action_textFind = new QAction(QString::fromLocal8Bit("����"),this);
    connect(action_textFind,&QAction::triggered,this,&MainWindow::textfind);
    ui->mainToolBar->addAction(action_textFind);

    findDialog = new QDialog(this);
    lineedit = new QLineEdit(findDialog);
    QPushButton *btn = new QPushButton(findDialog);
    btn->setText("find Next:");
    connect(btn,&QPushButton::clicked,this,&MainWindow::findNext);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineedit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);



    highlighter = new MySyntaxHighlighter(ui->textEdit->document());

    //html
    ui->textEdit->append(tr("<h1><font color = red >use html</font></h1>"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    
    //�ӿ���������޷���������
    QTextDocument *document = ui->textEdit->document();
    QTextFrame * frame = document->rootFrame();
    QTextFrame::iterator it;
    for (it = frame->begin();!it.atEnd();++it) {
        QTextFrame *childFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if(childFrame)
            qDebug() <<"frame";      
        else if (childBlock.isValid()) {
            qDebug() << "block:" << childBlock.text();
        }
    }
}

void MainWindow::showTextBlock()
{

    QTextDocument *document = ui->textEdit->document();   //��ȡ�ĵ�����
    QTextBlock block = document->firstBlock();   // ��õ�һ���ı���
    for(int i =0 ;i <document->blockCount();i++)
    {
        qDebug() << tr("Block %1 ,Block_first_line_num : %2,long :%3,content:")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length()) << block.text();
        block = block.next();   //��ȡ��һ���ı���
    }
}
//��������
void MainWindow::setTextfont(bool checked)
{
     qDebug() << "ok" <<endl;
    //�鿴�Ƿ�ѡ��״̬
    if(checked)
    {
        qDebug() << "ok" <<endl;
        QTextCursor cursor = ui->textEdit->textCursor();  //��ȡ���
        QTextBlockFormat blockFormat;   //�ı����ʽ
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        //ʹ������
        charFormat.setFont((QFont(QString::fromLocal8Bit("����"),12,QFont::Bold,true)));
        charFormat.setFontUnderline(true);
        cursor.setCharFormat(charFormat);
        cursor.insertText(QString::fromLocal8Bit("��������"));

    }
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format ;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2,2,format);

}

void MainWindow::insertList()
{
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

void MainWindow::insertImage()
{
    QTextImageFormat format;
    format.setName(":/pic/mengnalisha.jpg");
    ui->textEdit->textCursor().insertImage(format);

}

void MainWindow::textfind()
{
    findDialog->show();
}

void MainWindow::findNext()
{
    QString string = lineedit->text();
    bool isFind = ui->textEdit->find(string,QTextDocument::FindBackward);
    if(isFind)
    {
        qDebug() << tr("line_num: %1 ,Column_num:%2").
                    arg(ui->textEdit->textCursor().blockNumber())
                    .arg(ui->textEdit->textCursor().columnNumber());
    }

}
