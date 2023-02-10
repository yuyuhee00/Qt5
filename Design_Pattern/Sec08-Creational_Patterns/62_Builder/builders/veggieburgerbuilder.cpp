#include "veggieburgerbuilder.h"


VeggieBurgerBuilder::VeggieBurgerBuilder(QObject *parent) : QObject(parent)
{
    qInfo() << this << "created";

}

VeggieBurgerBuilder::~VeggieBurgerBuilder()
{
    qInfo() << this << "destroyed";
}


void VeggieBurgerBuilder::setIngredients(QStringList value)
{
    m_ingredients = value;
}

iMeal *VeggieBurgerBuilder::build()
{
    //goal here is to create a completed object ready for use
    Burger* burger = new Burger();
    prepair();
    cook();
    burger->setIngredients(m_ingredients);
    burger->prepair();
    return burger;
}


void VeggieBurgerBuilder::prepair()
{
    qInfo() << this << "prepairing the kitchen";
}

void VeggieBurgerBuilder::cook()
{
     qInfo() << this << "cooking veggie patty";
     qInfo() << this << "Adding veggie patty";
     m_ingredients.append("veggie patty");
}
