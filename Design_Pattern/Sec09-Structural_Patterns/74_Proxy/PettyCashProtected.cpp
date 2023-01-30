#include "PettyCashProtected.h"

PettyCashProtected::PettyCashProtected()
{
    balance = 500;
}

bool PettyCashProtected::withdraw(int amount)
{
    if(amount > balance)
        return false;

    balance -= amount;
    return true;
}

int PettyCashProtected::getBalance()
{
    return balance;
}
