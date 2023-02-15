#ifndef TURKEYBURGERBUILDER_H
#define TURKEYBURGERBUILDER_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iBuilder.h"
#include "../interfaces/iMeal.h"

class TurkeyBurgerBuilder : public QObject, public iBuilder
{
    Q_OBJECT

public:
    explicit TurkeyBurgerBuilder(QObject *parent = nullptr);
    ~TurkeyBurgerBuilder();

signals:

    // iBuilder interface
public:
    void setIngredients(QStringList value) override;
    void prepair() override;
    void cook() override;
    iMeal *build() override;

private:
    QStringList m_ingredients;
};

#endif // TURKEYBURGERBUILDER_H
