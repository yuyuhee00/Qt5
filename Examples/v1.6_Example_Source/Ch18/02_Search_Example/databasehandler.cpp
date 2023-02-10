#include "databasehandler.h"
#include <QDir>
#include <QDebug>

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject(parent)
{
}

void DatabaseHandler::connectToDataBase()
{
    QString dirPath = QDir::currentPath();
    dirPath.append("/" DATABASE_NAME);

    QFile(dirPath).remove(dirPath);
    this->restoreDataBase();
}

bool DatabaseHandler::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "데이터베이스 연결 실패.";
        return false;
    }
}

bool DatabaseHandler::openDataBase()
{
    QString dirPath = QDir::currentPath();
    dirPath.append("/" DATABASE_NAME);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(dirPath);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DatabaseHandler::closeDataBase()
{
    db.close();
}

bool DatabaseHandler::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE RECEIVE_MAIL ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "TIME    TIME         NOT NULL,"
                        "MESSAGE INTEGER      NOT NULL,"
                        "RANDOM  VARCHAR(255) NOT NULL"
                    " )"
                    )){
        qDebug() << "테이블 생성 에러 : "
                 << query.lastError().text();
        return false;
    } else {
        return true;
    }
}

bool DatabaseHandler::insertIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO "
                  "RECEIVE_MAIL (TIME, RANDOM, MESSAGE) "
                  "VALUES (:TIME, :RANDOM, :MESSAGE )");

    query.bindValue(":TIME",        data[0].toTime());
    query.bindValue(":MESSAGE",      data[1].toInt());
    query.bindValue(":RANDOM",     data[2].toString());

    if(!query.exec()){
        qDebug() << "데이터 삽입 에러 - "
                 << query.lastError().text();
        return false;
    } else {
        return true;
    }
}

DatabaseHandler::~DatabaseHandler()
{
}

