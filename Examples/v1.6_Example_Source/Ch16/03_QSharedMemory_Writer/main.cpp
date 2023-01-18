#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("QSharedMemory Writer 예제");
    w.show();

    return a.exec();
}
