#include <QCoreApplication>

/*

  What
  Visitor design patterns

  Description
  Represent an operation to be performed on the elements of an object structure.
  - Visitor lets you define a new operation without changing the classes of the elements on which it operates.

  Why
  And, you don't want to have to query the type of each node and cast the pointer to the correct type before performing the desired operation.

  Example
  Interfaces to the rescue!

  Note - using interfaces simplifies this to the point that its almost not even the same pattern

 */

#include "cart.h"
#include "shirt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cart cart;
    Shirt shirt;
    shirt.accept(&cart);


    return a.exec();
}
