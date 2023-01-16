#include <QCoreApplication>

/*

  What:
  code deprecation

  Description:
  Findings better ways to do things
  Some times you will want developers to use the better way

  Why:
  Can not remove the older function or it may break things
  But you want them to use the new way

  Example
  Q_DECL_DEPRECATED
  void original() Q_DECL_DEPRECATED;

 */


#include "machine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Machine machine;
    machine.original();

    return a.exec();
}
