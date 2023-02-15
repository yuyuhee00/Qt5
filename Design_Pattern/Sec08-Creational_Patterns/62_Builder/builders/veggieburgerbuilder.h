#ifndef VEGGIEBURGERBUILDER_H
#define VEGGIEBURGERBUILDER_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iBuilder.h"
#include "../interfaces/iMeal.h"

class VeggieBurgerBuilder : public QObject, public iBuilder
{
    Q_OBJECT

public:
    explicit VeggieBurgerBuilder(QObject *parent = nullptr);
    ~VeggieBurgerBuilder();

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

#endif // VEGGIEBURGERBUILDER_H
