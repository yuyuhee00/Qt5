#include <QCoreApplication>

/*
 What
 QMake starting a script before compiling

 Desription
 Preferred in Qt 5x
 Optional in Qt 6x

 Why
 This is Qts propritary build system

 Example
 Running python file

 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
