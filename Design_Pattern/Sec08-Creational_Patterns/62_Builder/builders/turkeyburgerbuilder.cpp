#include "turkeyburgerbuilder.h"


TurkeyBurgerBuilder::TurkeyBurgerBuilder(QObject *parent) : QObject(parent)
{
    qInfo() << this << "created";

}

TurkeyBurgerBuilder::~TurkeyBurgerBuilder()
{
    qInfo() << this << "destroyed";
}


void TurkeyBurgerBuilder::setIngredients(QStringList value)
{
    m_ingredients = value;
}

iMeal *TurkeyBurgerBuilder::build()
{
    //goal here is to create a completed object ready for use
    Burger* burger = new Burger();
    prepair();
    cook();
    burger->setIngredients(m_ingredients);
    burger->prepair();
    return burger;
}

void TurkeyBurgerBuilder::prepair()
{
    qInfo() << this << "prepairing the kitchen";
}

void TurkeyBurgerBuilder::cook()
{
     qInfo() << this << "cooking turkey patty";
     qInfo() << this << "Adding turkey patty";
     m_ingredients.append("turkey patty");
}
