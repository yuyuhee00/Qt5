#include <QCoreApplication>

/*
 What
 Text Streams

 Description
 Let the data flow

 Why
 We want fast encoded text without worrying about the details

 Example
 QTextStream

 */

#include <QDebug>
#include <QFile>
#include <QTextStream>

void writeFile(QFile &file)
{
    qInfo() << "Writing lines";
    QTextStream stream(&file); //let this handle the details for us, speed, encoding all that
    QString line = "Hello World";

    for(int i = 0; i < 100; i++)
    {
        stream << line << "\r\n";
    }
}

void readFile(QFile &file)
{
    qInfo() << "Reading lines";
    QTextStream stream(&file); //let this handle the details for us, speed, encoding all that

    stream.seek(0);
    QString line;
    int lines = 0;

    while (stream.readLineInto(&line))
    {
        //Do something with the line
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
