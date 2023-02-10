#include "dialog.h"

#include <QApplication>
#include <QDesktopServices>

/*
 What
 Desktop services

 Description
 Using the desktop and opening files with their handler

 Why
 Makes life super easy

 Example
 Opening URLs and making a custom handler

 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;

    QDesktopServices::setUrlHandler("help", &w, "showHelp");

    w.show();

    return a.exec();
}
