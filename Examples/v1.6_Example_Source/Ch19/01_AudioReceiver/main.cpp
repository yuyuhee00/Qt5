#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("마이크 신호 수신 예제");
    w.show();

    return a.exec();
}
