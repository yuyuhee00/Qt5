#include <QCoreApplication>

/*

  What
  Creating a shared lib

  Description
  How to make a basic lib

  Why
  Code should be split into smaller more managable chunks

  Example
  Very basic lib
  Add upload class
  link the lib to the app

  Look at the PRO files - ensure ordered
INCLUDEPATH += $$PWD/../uploader
DEPENDPATH += $$PWD/../uploader

go to command line
ldd ./myapp
myapp$ ldd ./myapp
    libuploader.so.1 => not found

    Talk about qt depoloy
    And the lib needs to be distributed with the app
    https://doc.qt.io/qt-5/deployment.html
 */

#include "../uploader/uploader_global.h"
#include "../uploader/uploader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Uploader up;
    up.upload("test.txt");

    return a.exec();
}
