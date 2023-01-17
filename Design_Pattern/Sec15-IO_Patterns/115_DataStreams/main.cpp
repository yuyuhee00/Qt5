#include <QCoreApplication>

/*
 What
 QDataStream

 Description
 Writing non-text data

 Why
 We want a simple way of saving comound or complex data

 Example
 Saving or loading class

 */

#include <QDebug>
#include <QFile>
#include <QDataStream>
#include "cat.h"

bool saveCat(QString path)
{
    Cat cat;
    cat.setAge(10);
    cat.setName("Othello");
    cat.setColor("Black");
    cat.setHungry(true);
    return cat.toFile(path);
}

void loadCat(QString path)
{
    Cat cat;
    cat.fromFile(path);
    cat.display();
}

void oneCat()
{
    qInfo() << "Saving one cat to a file";
    QString path = "one-cat.txt";
    if(saveCat(path))
    {
        loadCat(path);
    }
    qInfo() << "Complete";
}

void saveCats()
{
    QList<Cat*> cats;
    for(int i = 0; i < 10; i++)
    {
        Cat *cat = new Cat();
        cat->setName("Cat " + QString::number(i));
        cat->setAge(i);
        cat->setColor("Some color here");
        cat->setHungry(true); // ALWAYS HUNGRY!!!
        cats.append(cat);
    }

    QFile file("all-cats.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return;
    }


    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_5_12); //setting a version lets Qt know what to do!

    foreach (Cat* cat, cats)
    {
        cat->toStream(stream);
    }

    file.close();
    qDeleteAll(cats);

}

void loadCats()
{
    QFile file("all-cats.txt");
     if(!file.open(QIODevice::ReadOnly))
     {
         qInfo() << file.errorString();
         return;
     }

     QDataStream stream(&file);
     stream.setVersion(QDataStream::Qt_5_12);

     QList<Cat*> cats;
     while (!stream.atEnd())
     {
        Cat* cat = new Cat();
        cat->fromStream(stream);
        cats.append(cat);
     }
     file.close();

     foreach(Cat *cat, cats)
     {
         cat->display();
     }

     qDeleteAll(cats);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    oneCat();

    saveCats();
    loadCats();

    return a.exec();
}
