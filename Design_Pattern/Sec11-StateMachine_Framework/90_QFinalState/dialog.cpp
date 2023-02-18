#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for(int i = 0; i < 10; i++)
        {
            QState *state = new QState();
            state->setObjectName("State " + QString::number(i));
            addState(state);
        }

    // The states are added as children!
    qInfo() << "Children:" << m_statemachine.children().length();

    // Add our final state
    QFinalState *final = new QFinalState();

     // could have used the state machines children!
    QState *p = qobject_cast<QState*>(m_states.last());
    p->addTransition(ui->pushButton, &QPushButton::clicked, final);

    connect(&m_statemachine, &QStateMachine::finished, this, &Dialog::stateFinished);

    m_statemachine.addState(final);
    m_statemachine.setInitialState(m_states.at(0));
    m_statemachine.start();
}

Dialog::~Dialog()
{
    qDeleteAll(m_states);
    m_states.clear();
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    if(m_statemachine.isRunning())
        qInfo() << "---------- Clicked ----------";
}


void Dialog::stateEntered()
{
    qInfo() << this->sender() << "Entered";
}

void Dialog::stateExited()
{
    qInfo() << this->sender() << "Exited";
}


void Dialog::stateFinished()
{
    qInfo() << this->sender() << "Finished";

    ui->lineEdit->setText("Complete");

    // After Finished, m_statemachine.isRunning() is false
    // ui->pushButton->setEnabled(false);

    QMessageBox::information(this,"Finished","The state machine has finished!");
}

void Dialog::addState(QState *state)
{
    state->assignProperty(ui->lineEdit, "text", state->objectName());
    int i = m_states.length();
    if(i > 0)
    {
        QState *p = qobject_cast<QState*>(m_states.at(i - 1));
        p->addTransition(ui->pushButton, &QPushButton::clicked, state);
    }

    connect(state, &QState::entered, this, &Dialog::stateEntered);
    connect(state, &QState::exited, this, &Dialog::stateExited);
    connect(state, &QState::finished, this, &Dialog::stateFinished);

    m_states.append(state);
    m_statemachine.addState(state); //QStates become children
}


