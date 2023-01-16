#include <QCoreApplication>

/*

  What
  Intro to the Qt State Machine Framework

  Description
  An applications state will change
  Want to create, track, react to those changes

  Why
  Applications need to act differently based on their state

  Example
  What is state
  https://doc.qt.io/qt-5/statemachine-api.html


 */

#include "bulb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bulb bulb; //this becomes part of the application state
    bulb.setPowered(true); // state change
    bulb.setPowered(false); // state change

    return a.exec();
}
