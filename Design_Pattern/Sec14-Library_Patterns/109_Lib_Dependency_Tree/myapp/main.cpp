#include <QCoreApplication>

/*
 What
 Adding a lib the standard way creates a dependancy tree

 Description
 What the lib uses the app should use
 This will help with linking and deployment issues
 however the app and lib can link to different things


 Why
 Mistakes happen

 Example
 Network in a lib

 ldd both app and lib and see the difference in includes

 Notice if the app is missing
 QT += network
 the build failed!

 This will make people mad!!!

 */

#include "../downloader/downloader.h"
#include "../downloader/downloader_global.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Downloader downloader;
    downloader.download("http://www.voidrealms.com");

    return a.exec();
}
