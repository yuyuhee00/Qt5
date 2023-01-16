#include <QCoreApplication>

/*

  What
  State design pattern

  Description
  Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

  Why
  We have an object to have a changable state

  Example
  Traffic Light
  https://sourcemaking.com/design_patterns/state

  Note...Qt has a QStateMachine we will cover later but this is different!
 */

#include "trafficlight.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TrafficLight tl;
    tl.start();

    return a.exec();
}
