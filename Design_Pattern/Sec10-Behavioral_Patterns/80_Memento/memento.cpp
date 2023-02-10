#include "memento.h"

Memento::Memento(QObject *parent) : QObject(parent)
{

}

void Memento::commit()
{
    m_command.clear();
    foreach(QString value, m_commands)
    {
        m_command.append(value + ";");
    }
}

void Memento::cancel()
{
    m_commands.clear();
}

void Memento::rollback()
{
    m_commands.clear();
    m_commands.append(m_command);
}

void Memento::addTransaction(QString value)
{
    m_commands.append(value);
}

QString Memento::command()
{
    return m_command;
}
