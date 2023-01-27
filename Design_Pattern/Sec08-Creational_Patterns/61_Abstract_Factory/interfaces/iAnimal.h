#ifndef IANIMAL_H
#define IANIMAL_H

/*
 * C++ has no built-in concepts of interfaces. You can implement it using abstract classes which
 * contains only pure virtual functions.
 *
 * class Interface
 * {
 *      public:
 *          Interface() {}
 *          virtual ~Interface() {}
 *
 *          virtual method() = 0;
 * };
 *
 */

class iAnimal {
public:
    virtual ~iAnimal() {}; //we are going to make some people mad... but we need to free the memory

    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void move() = 0;
};

#endif // IANIMAL_H
