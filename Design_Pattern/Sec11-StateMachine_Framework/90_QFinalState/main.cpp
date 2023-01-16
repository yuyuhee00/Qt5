#include "dialog.h"

#include <QApplication>

/*

  What
  QFinalState example

  Description
  Create a non-looping state

  Why
  We want a state machine that ends instead of looping

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
