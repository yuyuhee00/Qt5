#include "cart.h"

Cart::Cart(QObject *parent) : QObject(parent)
{

}


void Cart::visit(iElement *element)
{
    qInfo() << this << " amount:" <<  element->amount();
}
