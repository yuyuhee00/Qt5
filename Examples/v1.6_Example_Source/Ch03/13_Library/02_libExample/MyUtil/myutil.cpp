#include "myutil.h"

MyUtil::MyUtil(QObject *parent) : QObject(parent)
{
}

int MyUtil::getSumValue(int a, int b)
{
    return a + b;
}

