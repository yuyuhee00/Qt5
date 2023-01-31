/*

  What
  Interpreter

  Description
  Interprets a language or data

  Why
  Typically data conversions between systems

  Example
  String converter

 */

#include <QCoreApplication>
#include <QDebug>
#include "interpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Interpreter interpreter;
    qInfo() << interpreter.interpret("123");
    qInfo() << interpreter.interpret("0xFF");
    qInfo() << interpreter.interpret("0xC0");
    qInfo() << interpreter.interpret("15");
    qInfo() << interpreter.interpret("Cat");

    return a.exec();
}
