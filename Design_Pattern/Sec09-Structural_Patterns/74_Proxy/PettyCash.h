#ifndef PETTYCASH_H
#define PETTYCASH_H


class PettyCash
{
public:
    PettyCash();

public:
    bool withdraw(int amount);
    int getBalance();

private:
    int balance;
};

#endif // PETTYCASH_H
