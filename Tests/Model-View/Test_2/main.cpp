#include "Widget.h"

#include <QApplication>


void test_1()
{
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel* model = new StringListModel(numbers);

    QListView* view = new QListView;
    view->setModel(model);
    view->show();
}

void listToList()
{
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QSplitter* splitter = new QSplitter;

    QAbstractItemModel* model = new StringListModel(numbers);

    QListView* firstListView = new QListView(splitter);
    QListView* secondListView = new QListView(splitter);

    firstListView->setModel(model);
    secondListView->setModel(model);

    secondListView->setSelectionModel(firstListView->selectionModel());

    splitter->setWindowTitle("List Model - List View");
    splitter->show();
}

void listToTable()
{
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QSplitter* splitter = new QSplitter;

    QAbstractItemModel* model = new StringListModel(numbers);

    QTableView* firstTableView = new QTableView(splitter);
    QTableView* secondTableView = new QTableView(splitter);

    firstTableView->setModel(model);
    secondTableView->setModel(model);

    secondTableView->setSelectionModel(firstTableView->selectionModel());

    splitter->setWindowTitle("List Model - Table Viewl");
    splitter->show();
}

void listToTree()
{
    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QSplitter* splitter = new QSplitter;

    QAbstractItemModel* model = new StringListModel(numbers);

    QTreeView* firstTreeView = new QTreeView(splitter);
    QTreeView* secondTreeView = new QTreeView(splitter);

    firstTreeView->setModel(model);
    secondTreeView->setModel(model);

    secondTreeView->setSelectionModel(firstTreeView->selectionModel());

    splitter->setWindowTitle("List Model - Tree View");
    splitter->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    // test_1();

    // listTolist();
    // listToTable();
    listToTree();

    return a.exec();
}
