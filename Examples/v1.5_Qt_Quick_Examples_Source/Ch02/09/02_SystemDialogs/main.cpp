#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine(QUrl("qrc:/dialog.qml"));
    return app.exec();
}
