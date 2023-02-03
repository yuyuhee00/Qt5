/*

  What
  QSaveFile

  Description
  Allows to easy transactions!
  - While writing, the contents will be written to a temporary file, and if no error happend,
    commit() will move it to the final file. This ensures that no data at the final file is lost in case an error happens
    while writing, an no partially-written file is ever present at the filenal location.
    Always use QSaveFile when saving entire documents to disk.

  Why
  Some times mistakes are made

  Example
  User input

 */

#include <QCoreApplication>
#include <QSaveFile>
#include <QTextStream>
#include <QFile>
#include <QDebug>

bool getInput(QString path)
{
    QSaveFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << file.errorString();
        return false;
    }

    qInfo() << "File:" << file.fileName();

    QTextStream stream(stdin);
    bool ok = false;

    while(true)
    {
        QString line = stream.readLine();

        if(line == "commit")
        {
            ok = file.commit();
            break;
        }
        else if(line == "cancel")
        {
            file.cancelWriting();
            break;
        }
        else
        {
            line.append("\r\n");
            file.write(line.toUtf8());
        }
    }

    qInfo() << "Complete!";
    return ok;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Enter text and hit return";
    qInfo() << "commit to save, cancel to abort";

    QString path = "test.txt";

    if(!getInput(path)) qInfo() << "User did not commit";


    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << file.errorString();
    }
    else
    {
        qInfo() << file.readAll();
        file.close();
    }

    return a.exec();
}
