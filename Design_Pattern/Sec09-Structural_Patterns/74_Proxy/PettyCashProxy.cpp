#include "PettyCashProxy.h"

PettyCashProxy::PettyCashProxy()
{

}

bool PettyCashProxy::widthdraw(Person& p, int amount)
{
    if(p.getName() == "Tom" || p.getName() == "Harry" || p.getName() == "Bubba")
        return realThing.withdraw(amount);
    else
        return false;
}

int PettyCashProxy::getBalance()
{
    return realThing.getBalance();
}
