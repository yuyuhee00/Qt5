#include "CustomWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScopedPointer<QWidget> widget( new CustomWidget());
    widget->resize(240, 120);
    widget->show();
    return a.exec();
}
