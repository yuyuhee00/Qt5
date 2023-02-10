#include "counter.h"
#include <QDebug>

Counter::Counter(QString mStr)
{
    mString = mStr;
    mValue = 0;
}

void Counter::setValue(int mValue)
{
    mValue = mValue;

    qDebug() << mString << ", mValue : " << mValue;
    //qDebug() << "mValue : " << mValue;
}
