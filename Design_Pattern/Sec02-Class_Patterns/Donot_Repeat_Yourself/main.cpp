#include <QCoreApplication>

/*
 What
 DRY - Don't repeat yourself
 https://en.wikipedia.org/wiki/Don%27t_repeat_yourself

 Description
 "Every piece of knowledge must have a single, unambiguous, authoritative representation within a system".
 The principle has been formulated by Andy Hunt and Dave Thomas in their book The Pragmatic Programmer


 Why
 Reducing repetition of software patterns

 Example
 When to use interfaces vs inheritance
 Interface is a contract between objects
 Inheritiance is changing the functionality of an object


 Interfaces - the contracts
 Classes - the implimentations
 Inheritance - modified implimentations
 */

#include "basicfridge.h"
#include "advancedfridge.h"
#include "basicradio.h"

void testBasic(BasicFridge *fridge)
{
    fridge->chill();
    fridge->freeze();
}

void testAdvanced(AdvancedFridge *fridge)
{
    fridge->chill();
    fridge->freeze();
    fridge->deepFreeze();

    if(fridge->radio())
    {
        fridge->radio()->play();
        //listen to music for a while...
        fridge->radio()->stop();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    BasicFridge fridge;

    AdvancedFridge afridge;
    BasicRadio radio;
    afridge.setRadio(&radio);

    testBasic(&fridge);
    testBasic(&afridge);

    testAdvanced(&afridge);

    return a.exec();
}
