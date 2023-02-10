#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_state1.setObjectName("State1");
    m_state2.setObjectName("State2");
    m_state3.setObjectName("State3");

    // Connect the states to slots
    connect(&m_state1, &QState::entered, this, &Dialog::stateEntered);
    connect(&m_state1, &QState::exited, this, &Dialog::stateExited);
    connect(&m_state2, &QState::entered, this, &Dialog::stateEntered);
    connect(&m_state2, &QState::exited, this, &Dialog::stateExited);
    connect(&m_state3, &QState::entered, this, &Dialog::stateEntered);
    connect(&m_state3, &QState::exited, this, &Dialog::stateExited);

    // Change the properties of the states
    m_state1.assignProperty(ui->lineEdit, "text", "In State 1");
    m_state2.assignProperty(ui->lineEdit, "text", "In State 2");
    m_state3.assignProperty(ui->lineEdit, "text", "In State 3");

    // add transitions from one state to another
    m_state1.addTransition(ui->pushButton, &QPushButton::clicked, &m_state2);
    m_state2.addTransition(ui->pushButton, &QPushButton::clicked, &m_state3);
    m_state3.addTransition(ui->pushButton, &QPushButton::clicked, &m_state1);

    // add them to the machine
    m_statemachine.addState(&m_state1);
    m_statemachine.addState(&m_state2);
    m_statemachine.addState(&m_state3);

    m_statemachine.setInitialState(&m_state1);
    m_statemachine.start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    qInfo() << "------------------ Clicked ------------------";
}

void Dialog::stateEntered()
{
    qInfo() << this->sender()->objectName() << "\tEntered";
}

void Dialog::stateExited()
{
    qInfo() << this->sender()->objectName() << "\tExited";
}
