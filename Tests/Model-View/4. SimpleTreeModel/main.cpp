#include "TreeModel.h"

#include <QApplication>
#include <QFile>
#include <QTreeView>
#include "TreeModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel model(file.readAll());
    file.close();

    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));
    view.show();

    return app.exec();
}
