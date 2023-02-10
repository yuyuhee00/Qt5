#include <QApplication>

#include <QtXml>
#include <QtDebug>

void retrievElements(QDomElement root, QString tag, QString att)
{
    QDomNodeList nodes = root.elementsByTagName(tag);

    qDebug() << "노드의 개수 = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();
            qDebug() << "속성 : " << e.attribute(att);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDomDocument document;
    QFile file("c:/dom.xml");
    if(!file.open(QIODevice::ReadOnly
                  | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return -1;
    } else {
        if(!document.setContent(&file)) {
            qDebug() << "Failed to reading.";
            return -1;
        }
        file.close();
    }

    QDomElement root =
            document.firstChildElement();

    retrievElements(root, "Korea", "Name");
    qDebug() << "Reading finished";

    return a.exec();
}
