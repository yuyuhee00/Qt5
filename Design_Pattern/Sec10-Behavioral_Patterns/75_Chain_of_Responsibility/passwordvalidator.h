#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QObject>
#include <QDebug>

class PasswordValidator : public QObject
{
    Q_OBJECT

public:
    explicit PasswordValidator(QObject *parent = nullptr);
    bool check(QString &value);

signals:

};

#endif // PASSWORDVALIDATOR_H
