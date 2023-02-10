
#include <QGuiApplication>
#include <QQuickView>
#include "triangleitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<TriangleItem>("Shapes", 1, 0, "Triangle");

    QQuickView view;
    view.setSource(QUrl("qrc:///triangletest.qml"));
    view.show();
    return app.exec();
}
