#include <QCoreApplication>

/*
 What
 QMAKE_PRE_LINK
 QMAKE_POST_LINK


 Description
 Executing a script after compiling and after linking

 Why
 Want to run after the executable is created

 Example
 https://stackoverflow.com/questions/6300148/get-qmake-to-execute-shell-script-after-build-finished-on-mac

 issues:
 Expect this to be slightly different based on OS and compiler!!!

 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
