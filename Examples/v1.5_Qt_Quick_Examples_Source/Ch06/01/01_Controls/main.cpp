#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/busyindicator.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/button.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/calendar.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/checkbox.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/combobox.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/groupbox.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/exclusivegroup.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/label.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/progressbar.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/radiobutton.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/slider_event.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/spinbox_event.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/switch.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/textarea.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/textfield.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/toolbutton.qml")));

    return app.exec();
}
