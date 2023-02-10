#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QDebug>

void viewDirs()
{
    QSplitter* splitter = new QSplitter;

    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath(QDir::rootPath());

    QTreeView* tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::rootPath()));

    QListView* list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::rootPath()));

    splitter->setWindowTitle("Tow views onto the same file system model");
    splitter->show();
}

void printDirs()
{
    QFileSystemModel* model = new QFileSystemModel;
    QObject::connect(model, &QFileSystemModel::directoryLoaded, [model](const QString& directory) {
        QModelIndex currentIndex = model->index(directory);
        int numRows = model->rowCount(currentIndex);
        for(int row = 0; row < numRows; ++row)
        {
            QModelIndex index = model->index(row, 0, currentIndex);
            QString text = model->data(index, Qt::DisplayRole).toString();
            qInfo() << "Name : " << text;
        }
    });
    model->setRootPath(QDir::rootPath());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //viewDirs();
    printDirs();

    return a.exec();
}
