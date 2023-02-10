/*
  What
  Iterator Pattern

  Description
  Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

  Why
  Make it easy to traverse a collection of objects

  Example
  Qt Containers - don't reinvent the wheel!
  https://sourcemaking.com/design_patterns/iterator

 */

#include <QCoreApplication>
#include <QDebug>

template <class T>
void fillContainer(T& container, int max)
{
    for(int i = 0; i < max; i++)
    {
       container.append(i);
    }
}

template <class T>
void fillSet(T& container, int max)
{
    for(int i = 0; i < max; i++)
    {
        container.insert(i);
    }
}

template <class T>
void fillPair(T& container, int max)
{
    for(int i = 0; i < max; i++)
    {
        container.insert(i, QString::number(i));
    }
}

template <class T>
void display(T container, QString message)
{
    qInfo() << message;
    // auto = T::iterator for example QVectorIterator::iterator
    for(auto i = container.begin(); i != container.end(); ++i)
    {
        qInfo() << *i ;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        QList<int> list;
        fillContainer<QList<int>>(list, 5);

        QVector<int> vector;
        fillContainer<QVector<int>>(vector, 5);

        QSet<int> set;
        fillSet<QSet<int>>(set, 5);

        QHash<int,QString> hash;
        fillPair<QHash<int,QString>>(hash, 5);

        QMap<int,QString> map;
        fillPair<QMap<int,QString>>(map, 5);

        display<QList<int>>(list, "Displaying a list");
        display<QSet<int>>(set, "Displaying a set");
        display<QVector<int>>(vector, "Displaying a vector");
        display<QHash<int,QString>>(hash, "Displaying a hash");
        display<QMap<int,QString>>(map, "Displaying a map");

        //qDeleteAll(list);
        list.clear();

       // qDeleteAll(vector);
        vector.clear();

        //qDeleteAll(set);
        set.clear();

        //qDeleteAll(hash);
        hash.clear();

        //qDeleteAll(map);
        map.clear();
    }

    return a.exec();
}
