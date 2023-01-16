#include "dialog.h"

#include <QApplication>
/*

  What
  Groups of states

  Description
  Create a non-looping groups of states

  Why
  We want a state machine that groups states
  Those states should not loop

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
