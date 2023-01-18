#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->getInfoButton, &QPushButton::pressed,
            this,              &Widget::getInfoButton);

    m_process = new QProcess();
    connect(m_process, SIGNAL(finished(int, QProcess::ExitStatus)),
            this,      SLOT(finished(int, QProcess::ExitStatus)));
    connect(m_process, SIGNAL(readyReadStandardError()),
            this,      SLOT(readyReadStandardError()));
    connect(m_process, SIGNAL(readyReadStandardOutput()),
            this,      SLOT(readyReadStandardOutput()));
    connect(m_process, SIGNAL(started()),
            this,      SLOT(started()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getInfoButton()
{
    QString program = "/bin/ls";
    QStringList arguments;
    arguments << "-ltr" << "/usr";

    m_process->start(program, arguments);
}

void Widget::finished(int exitCode,
                      QProcess::ExitStatus exitStatus)
{
    qDebug() << "Exit Code :" << exitCode;
    qDebug() << "Exit Status :" << exitStatus;
}

void Widget::readyReadStandardError()
{
    qDebug() << Q_FUNC_INFO << "ReadyError";
}

void Widget::readyReadStandardOutput()
{
  QByteArray buf = m_process->readAllStandardOutput();

  ui->textEdit->setText(buf);
}

void Widget::started()
{
  qDebug() << "Proc Started";
}
