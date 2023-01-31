#include "cart.h"

Cart::Cart(QObject *parent) : QObject(parent)
{
    m_total = 0.0;
}


void Cart::visit(iElement *element)
{
    m_total += element->amount();

    qInfo() << this << " amount:" <<  element->amount();
    qInfo() << this << " Total    : :" <<  m_total;
}
