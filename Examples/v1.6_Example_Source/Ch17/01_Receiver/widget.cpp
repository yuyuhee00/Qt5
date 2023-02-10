#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->connectionButton, SIGNAL(pressed()),
            this, SLOT(connectButton()));

    m_serialSettings.baudRate       = 115200;
    m_serialSettings.dataBits       = QSerialPort::Data8;
    m_serialSettings.parity         = QSerialPort::NoParity;
    m_serialSettings.stopBits       = QSerialPort::OneStop;
    m_serialSettings.flowControl    = QSerialPort::NoFlowControl;

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->comboBox->addItem(info.portName());

    m_serial = new QSerialPort(this);
    connect(m_serial, SIGNAL(error(QSerialPort::SerialPortError)),
            this,     SLOT(error(QSerialPort::SerialPortError)));
    connect(m_serial, SIGNAL(readyRead()),
            this,     SLOT(readData()));

}

void Widget::connectButton()
{
    if(m_serial->isOpen())
        return;

    QString devName = ui->comboBox->currentText().trimmed();
    m_serialSettings.portName = devName;

    m_serial->setPortName(m_serialSettings.portName);
    m_serial->setBaudRate(m_serialSettings.baudRate);
    m_serial->setDataBits(m_serialSettings.dataBits);
    m_serial->setParity(m_serialSettings.parity);
    m_serial->setStopBits(m_serialSettings.stopBits);
    m_serial->setFlowControl(m_serialSettings.flowControl);

    if (!m_serial->open(QIODevice::ReadWrite)) {
        qDebug() << "에러메시지 :" << m_serial->errorString();
    }
}


void Widget::error(QSerialPort::SerialPortError err)
{
    if (err == QSerialPort::ResourceError) {
        qDebug() << Q_FUNC_INFO
                 << "Critical Error : "
                 << m_serial->errorString();

        m_serial->close();
    }
}

void Widget::readData()
{
    const QByteArray data = m_serial->readAll();
    ui->receiveMsgLabel->setText(data);
}

Widget::~Widget()
{
    delete ui;
}
