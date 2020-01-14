#include "myconsole.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyConsole w;
    w.show();

    return a.exec();
}
