/*
 *
 What
 Text Streams

 Description
 Let the data flow
 - QTextStream uses a Unicode based buffer,
    and QTextCodec is used by QTextStream to automatically support different charactoer sets.s

 Why
 We want fast encoded text without worrying about the details

 Example
 QTextStream

 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

void writeFile(QFile &file)
{
    qInfo() << "Writing lines";

    // let this handle the details for us, speed, encoding all that
    QTextStream stream(&file);
    QString line = "Hello World";

    for(int i = 0; i < 100; i++)
    {
//        stream << line << "\r\n";
        stream << QString::asprintf("%02d : %s\r\n", i, line.toStdString().c_str());
    }
}

void readFile(QFile &file)
{
    qInfo() << "Reading lines";

    // let this handle the details for us, speed, encoding all that
    QTextStream stream(&file);

    stream.seek(0);
    QString line;
    int lines = 0;

    while (stream.readLineInto(&line))
    {
        // Do something with the line
        qInfo() << QString::asprintf("%02d : %s", lines, line.toStdString().c_str());
        lines++;
    }
    qInfo() << lines << "lines read";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("data.txt");
    if(file.open(QIODevice::ReadWrite))
    {
        writeFile(file);

        //any delay - then close the file

        readFile(file);
    }
    else
    {
        qCritical() << file.errorString();
    }

    return a.exec();
}
