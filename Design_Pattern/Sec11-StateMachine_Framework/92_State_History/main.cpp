#include "dialog.h"

#include <QApplication>

/*
 What
 Navigating states

 Description
 Remembering a state and revisiting it

 Why
 Sometimes we want to undo

 Example
 Navigating and editing state
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
