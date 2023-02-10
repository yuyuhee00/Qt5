#ifndef PETTYCASH_H
#define PETTYCASH_H

#include "Person.h"
#include "PettyCashProtected.h"

class PettyCash
{
public:
    PettyCash();

public:
    bool widthdraw(Person& p, int amount);
    int getBalance();

private:
    PettyCashProtected realThing;
};

#endif // PETTYCASH_H
