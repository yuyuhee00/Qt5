#include <QCoreApplication>

/*

 SOLID - https://en.wikipedia.org/wiki/SOLID
 Single Responsibility Principle
 Open/Closed Principle
 Liskov Substitution Principle
 Interface Segregation Principle
 Dependency Inversion Principle

 What
 Interface Segregation Principle

 Define
 Clients should not be forced to depend upon interfaces that they do not use
 - Many client-specific interfaces are better than one general-purpose interface.

 Why
 Adding too much to an interface could cause un-needed code, and undesirable effects

 Example
 Flying things

 */

#include "interfaces/iFlying.h"
#include "interfaces/iMachine.h"
#include "bird.h"
#include "airplane.h"

void trip(iFlying *obj)
{
    obj->fly();
    obj->land();
}

void checkFuel(iMachine *obj)
{
    obj->refuel();
}

void testBird()
{
    Bird bird;
    trip(&bird);
}

void testPlane()
{
    AirPlane plane;
    trip(&plane);
    checkFuel(&plane);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testBird();
    testPlane();

    return a.exec();
}











