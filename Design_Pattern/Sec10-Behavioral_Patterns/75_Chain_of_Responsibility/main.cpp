/*

    What
    Chain of responsibility

    Description
    A way of passing a request between a chain of objects

    Why
    Single point of entry, very expandable

    Example
    Password compexity checker

    also use https://regex101.com/

* 아래 는 Qt 6에서 제거되었지만 이식의 용이성을 위해 Qt5Compat에 보관 된 클래스가 나열되어 있다. 또한 Qt6에서 대신 사용할 클래스도 포함된다.

Qt 5 Class                      Qt 6 Replacement
QLinkedList                     std::list*
QRegExp                         QRegularExpression
QStringRef                      QStringView
QXmlSimpleReader        QXmlStreamReader
QTextCodec                    QStringConverter
QTextEncoder                 QStringEncoder
QTextDecoder                 QStringDecoder

 */

#include <QCoreApplication>
#include <QDebug>
#include "passwordvalidator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PasswordValidator validator;
    QString password = "helloworld!@1";
    bool passed = validator.check(password);
    qInfo() << "Passed: " << passed;

    return a.exec();
}
