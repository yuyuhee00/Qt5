#include <QCoreApplication>

/*
 What
 POST_TARGETDEPS

 Description
 Executing a script after compiling

 Why
 Want to run after build, and before linking

 Example
 POST_TARGETDEPS fires off BEFORE your exe is created (in Windows) or BEFORE it is recreated (in Linux)!
 QMake works differently depending upon the platform and the complier.


 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
