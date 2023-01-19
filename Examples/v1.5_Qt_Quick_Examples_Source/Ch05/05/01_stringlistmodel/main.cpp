
#include <QGuiApplication>
#include <QStringList>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char ** argv)
{
    QGuiApplication app(argc, argv);

    QStringList dataList;
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

    QQuickView view;

    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("MyModel", QVariant::fromValue(dataList));

    view.setSource(QUrl("qrc:view.qml"));
    view.show();

    return app.exec();
}

