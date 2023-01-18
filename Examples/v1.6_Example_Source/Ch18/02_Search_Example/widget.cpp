#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->timeFROM->setDisplayFormat("hh:mm:ss");
    ui->timeTO->setDisplayFormat("hh:mm:ss");

    dbHandler = new DatabaseHandler();
    dbHandler->connectToDataBase();

    for(int i = 0; i < 10; i++)
    {
        QVariantList data;


        QTime currTime = QTime::currentTime();
        currTime = currTime.addSecs(i*1000);

        int random = qrand();
        data.append(currTime);
        data.append(random);
        data.append("메시지 : "
                        + QString::number(random));

        dbHandler->insertIntoTable(data);
    }

    this->setupModel("RECEIVE_MAIL",
                     QStringList() << "ID"
                                   << "시간"
                                   << "번호"
                                   << "메시지"
               );

    this->createUserInterface();
}

void Widget::setupModel(const QString &tableName,
                        const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }

    model->setSort(0,Qt::AscendingOrder);
}

void Widget::createUserInterface()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0 ; i < 4 ; i++)
        ui->tableView->setColumnWidth(i, 100);

    model->select(); // 테이블로부터 데이터를 Fetche
    ui->timeFROM->setTime(QTime::currentTime());
    ui->timeTO->setTime(QTime::currentTime());

    connect(ui->pbtSearch, SIGNAL(pressed()),
            this,          SLOT(onPushButton()));
}

void Widget::onPushButton()
{

    QString str = QString("TIME between '%3' and '%4'")
                        .arg(ui->timeFROM->time().toString("hh:mm:ss"));

    qDebug() << Q_FUNC_INFO << str;


    model->setFilter(QString( "TIME between '%3' and '%4'")                     
                     .arg(ui->timeFROM->time().toString("hh:mm:ss"),
                          ui->timeTO->time().toString("hh:mm:ss")));
//    model->setFilter(QString( "TIME between '%3' and '%4'")
//                     .arg(ui->timeFROM->time().toString("hh:mm:ss"),
//                          ui->timeTO->time().toString("hh:mm:ss")));

    model->select(); // 테이블로부터 데이터를 Fetche
}

Widget::~Widget()
{
    delete ui;
}
