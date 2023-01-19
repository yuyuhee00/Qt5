#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QSqlDatabase db;
    QSqlTableModel *model;

    void initializeDataBase();
    void creationTable();
    void insertDataToTable();
    void initializeModel();

private slots:
    void slotPbtUpdate();
    void slotPbtDelete();
};

#endif // WIDGET_H
