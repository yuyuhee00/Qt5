/*

  What
  Using a shared lib

  Description
  How to use a shared lib

  Why
  Someone else created the lib or its not a part of this project

  Example
  Add external lib from 14-2

  Special notice to debug vs release!!!
myapp$ ldd ./myapp
    libuploader.so.1 => not found

    Talk about qt depoloy
    And the lib needs to be distributed with the app
    https://doc.qt.io/qt-5/deployment.html

 */
#include <QCoreApplication>
#include "../107_Creating_Shared_Library/uploader/uploader.h"
#include "../107_Creating_Shared_Library/uploader/uploader_global.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Uploader up;
    up.upload("test.txt");

    return a.exec();
}
