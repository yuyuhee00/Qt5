#include <QCoreApplication>

/*

  What
  Null Object pattern

  Decription
  The intent of a Null Object is to encapsulate the absence of an object by providing a substitutable alternative

  Why
  Usable but does nothing

  Example
  Logger

 */

#include <QFile>
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Logger logger;

    logger.log("Hello World"); // Should warn us and somewhat works!

    QFile file("test.txt");
    logger.setFile(&file);

    logger.log("Hello again");

    file.close();

    return a.exec();
}
