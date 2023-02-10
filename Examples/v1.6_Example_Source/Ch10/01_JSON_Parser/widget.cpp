#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtJSONParser, SIGNAL(pressed()),
            this, SLOT(slotPbtJSONParser()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotPbtJSONParser()
{
    qDebug() << Q_FUNC_INFO;

    QString inputFilePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     QDir::currentPath(),
                                     tr("JSON Files (*.json)"));

    QFile file(inputFilePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file.";
            return;
    }

    QString data = file.readAll();
    file.close();

    ui->textEdit->clear();
    parseJSON(data);
}

void Widget::parseJSON(const QString &data)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toLocal8Bit());
    QJsonObject jsonObj = jsonResponse.object();

    addText(jsonObj["time"].toString().append("\n"));
    addText(jsonObj["date"].toString().append("\n"));

    if(jsonObj["success"].toBool() == true)
        addText(QString("success : true \n"));
    else
        addText(QString("success : false \n"));

    QJsonArray jsonArray = jsonObj["properties"].toArray();

    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();

        QString property = obj["PropertyName"].toString();
        QString key      = obj["key"].toString();

        QString arrayData;
        arrayData = QString("property : %1 , key : %2 \n")
                                .arg(property).arg(key);

        addText(arrayData);
    }
}

void Widget::addText(const QString &addLine)
{
    ui->textEdit->insertPlainText(addLine);
}



