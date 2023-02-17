#ifndef IELEMENT_H
#define IELEMENT_H

class iVisitor;

class iElement
{
public:
    virtual ~iElement() {} //this will make people mad

    virtual void accept(iVisitor* visitor) = 0;
    virtual double amount() = 0;
};


#endif // IELEMENT_H
