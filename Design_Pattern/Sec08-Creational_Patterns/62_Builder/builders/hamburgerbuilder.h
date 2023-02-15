#ifndef HAMBURGERBUILDER_H
#define HAMBURGERBUILDER_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iBuilder.h"
#include "../interfaces/iMeal.h"

class HamBurgerBuilder : public QObject, public iBuilder
{
    Q_OBJECT

public:
    explicit HamBurgerBuilder(QObject *parent = nullptr);
    ~HamBurgerBuilder();

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

#endif // HAMBURGERBUILDER_H
