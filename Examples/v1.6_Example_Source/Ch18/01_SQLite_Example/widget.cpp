#include "widget.h"
#include "ui_widget.h"

#include <QTableView>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initializeDataBase();
    creationTable();
    insertDataToTable();
    initializeModel();
    ui->tableView->setModel(model);

    connect(ui->pbtUpdate, SIGNAL(pressed()),
            this,          SLOT(slotPbtUpdate()));
    connect(ui->pbtDelete, SIGNAL(pressed()),
            this,          SLOT(slotPbtDelete()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeDataBase()
{
    QFile::remove("./testdatabase.db");

    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("./testdatabase.db" );

    if( !db.open() )
        qDebug() << db.lastError();
}

void Widget::creationTable()
{
    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS names "
                 "("
                 "  id INTEGER UNIQUE PRIMARY KEY, "
                 "  firstname VARCHAR(30), "
                 "  lastname  VARCHAR(30)"
                 ")" );

    if( !qry.exec() )
        qDebug() << qry.lastError();
}

void Widget::insertDataToTable()
{
    QSqlQuery qry;

    qry.prepare( "INSERT INTO names "
                 "(id, firstname, lastname) "
                 "VALUES "
                 "(1, 'John', 'Doe')" );
    if( !qry.exec() )
      qDebug() << qry.lastError();

    qry.prepare( "INSERT INTO names "
                 "(id, firstname, lastname) "
                 "VALUES"
                 "(2, 'Jane', 'Doe')" );
    if( !qry.exec() )
      qDebug() << qry.lastError();

    qry.prepare( "INSERT INTO names "
                 "(id, firstname, lastname) "
                 "VALUES "
                 "(3, 'James', 'Doe')" );
    if( !qry.exec() )
      qDebug() << qry.lastError();

}

void Widget::initializeModel()
{
    model = new QSqlTableModel(this, db);

    model->setTable("names");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
}

void Widget::slotPbtUpdate()
{
    QSqlQuery qry;
    qry.prepare( "UPDATE names "
                 "SET firstname = 'Eddy', "
                 "lastname = 'Kim' WHERE id = 1" );
    if( !qry.exec() )
      qDebug() << qry.lastError();

    model->setTable("names");
    model->select();
    ui->tableView->setModel(model);
}

void Widget::slotPbtDelete()
{
    QSqlQuery qry;

    qry.prepare( "DELETE FROM names WHERE id = 1" );
    if( !qry.exec() )
      qDebug() << qry.lastError();

    model->setTable("names");
    model->select();
    ui->tableView->setModel(model);
}









