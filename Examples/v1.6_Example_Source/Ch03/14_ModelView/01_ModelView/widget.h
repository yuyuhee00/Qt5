#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QFileSystemModel>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QListView>
#include <QtWidgets/QFileSystemModel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
