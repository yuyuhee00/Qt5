#ifndef NOTQT_H
#define NOTQT_H

#include <QString>
class NotQt
{
public:
    NotQt();
    void setObjectName(QString name);
    QString objectName();

private:
    QString m_objectname;
};

#endif // NOTQT_H
