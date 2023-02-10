#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    createStates();
    m_statemachine.start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textEdited(const QString &arg1)
{
    if(!m_current) return;
    qInfo() << "Editing: " << arg1;
    m_current->setObjectName(arg1);
    m_current->assignProperty(ui->lineEdit, "text", m_current->objectName());
}

void Dialog::on_btnBack_clicked()
{
    if(!m_statemachine.isRunning())
        return;
    qInfo() << "Back Clicked";
}

void Dialog::on_btnNext_clicked()
{
    if(!m_statemachine.isRunning())
        return;
    qInfo() << "Next Clicked";
}

void Dialog::stateEntered()
{
    if(!this->sender()) return;
    qInfo() << this->sender() << "Entered";
    m_current = qobject_cast<QState*>(this->sender());
}

void Dialog::stateExited()
{
    if(!this->sender()) return;
    qInfo() << this->sender() << "Exited";
}

void Dialog::stateFinished()
{
    if(!this->sender()) return;
    qInfo() << this->sender() << "Finished";
}

void Dialog::createStates()
{
    QState* previous = nullptr;

    for(int i = 0; i< 5; i++)
    {
        QState *state = new QState(&m_root);
        state->setObjectName("State: " + QString::number(i));
        if(i == 0)
            m_root.setInitialState(state);

        connect(state, &QState::entered, this, &Dialog::stateEntered);
        connect(state, &QState::exited, this, &Dialog::stateExited);
        connect(state, &QState::finished, this, &Dialog::stateFinished);
        state->assignProperty(ui->lineEdit, "text", state->objectName());

        if(previous)
        {
            state->addTransition(ui->btnBack, &QPushButton::clicked, previous);
            previous->addTransition(ui->btnNext, &QPushButton::clicked, state);
        }

        previous = state;
    }

    m_statemachine.addState(&m_root);
    m_statemachine.setInitialState(&m_root);
}
