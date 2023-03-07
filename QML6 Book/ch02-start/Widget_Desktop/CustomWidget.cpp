#include <QApplication>
#include "CustomWidget.h"
#include <QVBoxLayout>

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    m_listWidget = new QListWidget(this);
    layout->addWidget(m_listWidget);

    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    m_pushButton = new QPushButton("Quit", this);
    layout->addWidget(m_pushButton);

    this->setLayout(layout);

    QStringList cities;
    cities << "Paris" << "London" << "Munich";
    foreach(const QString& city, cities) {
        m_listWidget->addItem(city);
    }

//    QObject::connect(m_listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));
//    QObject::connect(m_lineEdit, SIGNAL(editingFinished()), this, SLOT(updateItem()));
//    QObject::connect(m_pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QObject::connect(m_listWidget, &QListWidget::itemClicked, this, &CustomWidget::itemClicked);
    QObject::connect(m_lineEdit, &QLineEdit::editingFinished, this, &CustomWidget::updateItem);
    QObject::connect(m_pushButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

CustomWidget::~CustomWidget()
{
}

void CustomWidget::itemClicked(QListWidgetItem *item)
{
    Q_ASSERT(item);
    m_lineEdit->setText(item->text());
}

void CustomWidget::updateItem()
{
    QListWidgetItem* item = m_listWidget->currentItem();
    if(item) {
        item->setText(m_lineEdit->text());
    }
}

