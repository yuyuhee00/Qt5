#ifndef CHEF_H
#define CHEF_H


#include <QObject>
#include <QDebug>

class Chef : public QObject
{
    Q_OBJECT

public:
    explicit Chef(QObject *parent = nullptr);

    void makeDinner();

signals:

private:
    virtual void prepair();
    virtual void cook();
    virtual void cleanup();
};


#endif // CHEF_H
