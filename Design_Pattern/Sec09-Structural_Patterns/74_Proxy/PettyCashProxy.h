#ifndef PETTYCASHPROXY_H
#define PETTYCASHPROXY_H

#include "Person.h"
#include "PettyCash.h"

class PettyCashProxy
{
public:
    PettyCashProxy();

public:
    bool widthdraw(Person& p, int amount);
    int getBalance();

private:
    PettyCash realThing;
};

#endif // PETTYCASHPROXY_H
