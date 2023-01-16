#include "dialog.h"

#include <QApplication>

/*

  What
  State machine example

  Description
  Pretty much strait from the documentation

  Why
  Simple, but needs a bit of explaining

  Example
  https://doc.qt.io/qt-5/statemachine-api.html

 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
