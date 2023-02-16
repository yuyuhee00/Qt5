#include "PettyCash.h"

PettyCash::PettyCash()
{
    balance = 500;
}

bool PettyCash::withdraw(int amount)
{
    if(amount > balance)
        return false;

    balance -= amount;
    return true;
}

int PettyCash::getBalance()
{
    return balance;
}
