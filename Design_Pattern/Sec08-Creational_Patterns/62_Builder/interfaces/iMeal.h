#ifndef IMEAL_H
#define IMEAL_H

#include <QString>
#include <QStringList>

class iMeal
{
public:
    virtual ~iMeal() {}; //we are going to make some people mad... but we need to free the memory

    virtual void prepair() = 0;
    virtual QStringList ingredients() = 0;
    virtual void setIngredients(QStringList list) = 0;
    virtual void show() = 0;
};


#endif // IMEAL_H
