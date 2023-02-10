#ifndef SHIRT_H
#define SHIRT_H

#include <QObject>
#include <QDebug>

#include "interfaces/iElement.h"
#include "interfaces/iVisitor.h"


class Shirt : public QObject, public iElement
{
    Q_OBJECT

public:
    explicit Shirt(QObject *parent = nullptr);

signals:

    // iElement interface
public:
    void accept(iVisitor *visitor) override;
    double amount() override;

private:
    double m_value;
};

#endif // SHIRT_H
