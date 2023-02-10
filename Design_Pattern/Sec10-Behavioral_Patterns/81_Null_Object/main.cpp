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

#include <QCoreApplication>
#include <QFile>
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Logger logger;

    logger.log("Hello World"); // Should warn us and somewhat works!

    QFile file("test.txt");
//    if(! file.open(QFile::ReadWrite | QFile::Text)) {
//        if(file.exists()) {
//            logger.setFile(&file);
//            logger.log("Hello again");
//            file.close();
//        }
//    }

    logger.setFile(&file);
    logger.log("Hello again");
    file.close();

    return a.exec();
}
