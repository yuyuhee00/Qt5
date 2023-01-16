#include "hamburgerbuilder.h"

HamBurgerBuilder::HamBurgerBuilder(QObject *parent) : QObject(parent)
{
    qInfo() << this << "created";

}

HamBurgerBuilder::~HamBurgerBuilder()
{
    qInfo() << this << "destroyed";
}


void HamBurgerBuilder::setIngredients(QStringList value)
{
    m_ingredients = value;
}

iMeal *HamBurgerBuilder::build()
{
    //goal here is to create a completed object ready for use
    Burger* burger = new Burger();
    prepair();
    cook();
    burger->setIngredients(m_ingredients);
    burger->prepair();
    return burger;
}


void HamBurgerBuilder::prepair()
{
    qInfo() << this << "prepairing the kitchen";
}

void HamBurgerBuilder::cook()
{
     qInfo() << this << "cooking beef patty";
     qInfo() << this << "Adding beef patty";
     m_ingredients.append("beef patty");
}
