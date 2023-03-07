#pragma once

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr);
    ~CustomWidget();

private slots:
    void itemClicked(QListWidgetItem* item);
    void updateItem();

private:
    QListWidget* m_listWidget;
    QLineEdit* m_lineEdit;
    QPushButton* m_pushButton;
};
