#ifndef IORDER_H
#define IORDER_H

class iOrder {
public:
    virtual ~iOrder() {} //This will make people mad

      virtual void execute() = 0;
};

#endif // IORDER_H
