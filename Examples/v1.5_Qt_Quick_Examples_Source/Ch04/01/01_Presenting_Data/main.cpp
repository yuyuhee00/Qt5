#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/listmodel_exam_1.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/listmodel_exam_2.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/list-view-header-footer.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/grid_exam_1.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/grid_exam_ani.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/xml_exam.qml")));

    return app.exec();
}
