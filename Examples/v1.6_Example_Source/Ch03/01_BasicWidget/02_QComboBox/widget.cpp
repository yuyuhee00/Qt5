#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QComboBox");

    combo = new QComboBox(this);
    combo->setGeometry(50, 50, 200, 30);

    combo->addItem(QIcon(":resources/browser.png"), "Application");
    combo->addItem(QIcon(":resources/browser.png"), "Graphics");
    combo->addItem("Database");
    combo->addItem("Network");

    connect(combo, SIGNAL(currentIndexChanged(int)),
            this,  SLOT(valueChanged(int)));

    QString str;
    str = combo->currentText();

    qDebug("Total Items : %d", combo->count());
}

void Widget::valueChanged(int index)
{
    int current_index = combo->currentIndex();
    qDebug("Current ComboBox index : %d, %d", index, current_index);
}

Widget::~Widget()
{
}
