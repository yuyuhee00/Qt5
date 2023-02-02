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

#include <QApplication>
#include "dialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    w.show();

    return a.exec();
}
