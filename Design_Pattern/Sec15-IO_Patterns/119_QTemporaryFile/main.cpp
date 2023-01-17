#include <QCoreApplication>

/*
 What
 Temp files!

 Description
 Working with a file we want to discard when we are done with

 Why
 Temp files make it easy to work with files we simply dont care about
 The file is deleted when the variable is destroyed

 Example
 Web Download size

 */

#include "downloader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Downloader downloader;
    downloader.download("http://www.voidrealms.com");

    return a.exec();

    //here
}
