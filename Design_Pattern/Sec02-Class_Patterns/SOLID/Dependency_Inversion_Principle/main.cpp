/*

 SOLID - https://en.wikipedia.org/wiki/SOLID
 Single Responsibility Principle
 Open/Closed Principle
 Liskov Substitution Principle
 Interface Segregation Principle
 Dependency Inversion Principle

 What
 Dependency Inversion Principle

 Define
 High-level modules should not depend on low-level modules. Both should depend on abstractions.
 Abstractions should not depend on details. Details should depend on abstractions.
 Based on other SOLID principles
 High-level and low-level modules depend on the abstraction.
 - One should "depend upon abstractions [not] concretion"

 Why
 If the details change, breaks could occur!
 The interfaces enable you to add new functionality without changing any existing code by adding new interface implementations

 Example
 Oven, Advanced Oven, Bad Oven

 */

#include <QCoreApplication>
#include "basicoven.h"
#include "badoven.h"
#include "advancedoven.h"
#include "interfaces/iOven.h"

void cook(iOven *oven)
{
    oven->bake();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BasicOven basicoven;
    AdvancedOven advancedoven;
    BadOven badoven;

    cook(&basicoven);
    cook(&advancedoven);
    cook(&badoven); //still works, but does break this princible, changes to basicoven will impact badoven!

    return a.exec();
}
