#ifndef CART_H
#define CART_H

#include <QObject>
#include <QDebug>

#include "interfaces/iElement.h"
#include "interfaces/iVisitor.h"

class Cart : public QObject, public iVisitor
{
    Q_OBJECT

public:
    explicit Cart(QObject *parent = nullptr);

signals:

    // iVisitor interface
public:
    void visit(iElement *element) override;

private:
    double m_total;
};

#endif // CART_H
