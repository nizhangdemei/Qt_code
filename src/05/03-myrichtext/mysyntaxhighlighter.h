#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QWidget>
#include <QSyntaxHighlighter>
class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument *parent = nullptr);

signals:
    
protected:
    void highlightBlock(const QString &text);
public slots:
};

#endif // MYSYNTAXHIGHLIGHTER_H
