#include "PettyCash.h"

PettyCash::PettyCash()
{

}

bool PettyCash::widthdraw(Person& p, int amount)
{
    if(p.getName() == "Tom" || p.getName() == "Harry" || p.getName() == "Bubba")
        return realThing.withdraw(amount);
    else
        return false;
}

int PettyCash::getBalance()
{
    return realThing.getBalance();
}
