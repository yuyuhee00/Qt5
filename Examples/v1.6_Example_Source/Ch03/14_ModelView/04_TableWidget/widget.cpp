#include "widget.h"
#include "ui_widget.h"
#include "checkboxheader.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(2);

    CheckBoxHeader* header = new CheckBoxHeader(Qt::Horizontal, ui->tableWidget);
    ui->tableWidget->setHorizontalHeader(header);
    connect(header, &CheckBoxHeader::checkBoxClicked,
            this,   &Widget::checkBoxClicked);

    QStringList nameList;
    nameList << "노트북" << "모바일" << "데스크탑" << "키보드" << "모니터";

    for(int i = 0; i < 5 ; i++)
    {
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *dateItem = new QTableWidgetItem("2021.05.07");
        dateItem->setCheckState(Qt::Checked);

        ui->tableWidget->setItem(i,0, dateItem);
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(nameList.at(i)));
    }
}

void Widget::checkBoxClicked(bool state)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        if(state)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}

Widget::~Widget()
{
    delete ui;
}
