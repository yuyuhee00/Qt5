#include <QCoreApplication>

/*
 What
 Storing passwords

 Description
 How to deal with sensitive info easily

 Why
 Passwords can be read from the disk

 Example
 https://doc.qt.io/qt-5/qcryptographichash.html
 Hashing

 */

#include <QTextStream>
#include <QCryptographicHash>
#include <QSettings>
#include <QDebug>

QString createHash(QString data)
{
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(data.toUtf8());
    return hash.result().toBase64();
}

void setPassword()
{
    QTextStream stream(stdin);
    qInfo() << "Enter a password";
    QString pass1 = stream.readLine();
    qInfo() << "Confirm the password";
    QString pass2 = stream.readLine();

    if(pass1 == pass2)
    {
        QString hashed = createHash(pass1);
        qInfo() << "Hashed:" << hashed;

        QSettings settings;
        settings.setValue("password", hashed);
    }
    else
    {
        qInfo() << "They dont match...";
        setPassword();
    }
}

void checkPassword()
{
    qInfo() << "Please enter the password you previously entered...";
    QTextStream stream(stdin);
    QSettings settings;
    QString password = stream.readLine();
    QString hashed = createHash(password);
    QString stored = settings.value("password", "").toString();

    qInfo() << "Hashed:" << hashed;
    qInfo() << "Stored:" << stored;

    if(stored == hashed)
    {
        qInfo() << "Correct!";
    }
    else
    {
        qInfo() << "Sorry try again";
        checkPassword();
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setPassword();
    checkPassword();

    return a.exec();
}
