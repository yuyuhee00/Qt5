#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include "databasehandler.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    DatabaseHandler *dbHandler;
    QSqlTableModel  *model;

    void setupModel(const QString &tableName,
                    const QStringList &headers);
    void createUserInterface();

private slots:
    void onPushButton();

};

#endif // WIDGET_H
