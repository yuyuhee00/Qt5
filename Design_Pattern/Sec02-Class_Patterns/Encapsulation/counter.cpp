#include "counter.h"

Counter::Counter(QObject *parent) : QObject(parent)
{
    //Notice our variables!!!
}

void Counter::count(int max)
{
    m_count = 0;
    m_max = max;
    performcount();
}

void Counter::performcount()
{
    for(int i = 0; i < m_max; i++)
    {
        m_count++;
        qInfo() << "count:" << m_count;
    }
}
