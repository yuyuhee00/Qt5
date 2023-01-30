#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person();

public:
    QString getName() const;
    void setName(const QString &newName);

private:
    QString name;

    static QString nameList[];
    static int next;
};

#endif // PERSON_H
