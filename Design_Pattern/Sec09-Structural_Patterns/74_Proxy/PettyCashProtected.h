#ifndef PETTYCASHPROTECTED_H
#define PETTYCASHPROTECTED_H


class PettyCashProtected
{
public:
    PettyCashProtected();

public:
    bool withdraw(int amount);
    int getBalance();

private:
    int balance;
};

#endif // PETTYCASHPROTECTED_H
