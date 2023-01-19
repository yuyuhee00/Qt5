#include <QGuiApplication>
#include <QQuickView>
#include "ellipseitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<EllipseItem>("Shapes", 1, 0, "Ellipse");

    QQuickView view;
    view.setSource(QUrl("qrc:///ellipse.qml"));
    view.show();

    return app.exec();
}
