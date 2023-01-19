#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/basic_circulargauge.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/circulargauge_style1.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/circulargauge_style2.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/circulargauge_style3.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/circulargauge_style4.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/circulargauge_style5.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/circulargauge_complete.qml")));

    return app.exec();
}
