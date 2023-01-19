#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/colordialog.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/filedialog.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/fontdialog.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/messagedialog.qml")));

    return app.exec();
}
