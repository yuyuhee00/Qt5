#include <QCoreApplication>

/*

  What
  Template design pattern

  Description
  The Template Method defines a skeleton of an algorithm in an operation, and defers some steps to subclasses
  - Let's subclasses redefine certain step of an algorithm without changing the algorithm's structure.
  - Base class declare algorithm placeholders; and derived classes implement the placeholders.

  Why
  We want to define what a class does but not how it does everything

  Example
  Chef

  Note I really don't like this, I tend to use interfaces, but Qt does use this in some classes
  For example - QTCPServer

 */

#include "baker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Baker baker;
    baker.makeDinner();

    return a.exec();
}
