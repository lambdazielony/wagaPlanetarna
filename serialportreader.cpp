#include "serialportreader.h"

#include <QCoreApplication>

SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialPortReader::handleError);
    connect(&m_timer, &QTimer::timeout, this, &SerialPortReader::handleTimeout);

    m_timer.start(1000);
    serialBuffer = "";
}

void SerialPortReader::handleReadyRead()
{
  QStringList bufferSplit = serialBuffer.split(",");
  if(bufferSplit.length() < 3){
      m_readData = m_serialPort->readAll();
      serialBuffer += QString::fromStdString(m_readData.toStdString());
  } else {
      m_standardOutput << bufferSplit[1] << endl;
      QStringList commandList = bufferSplit[1].split(" ");
      emit commandReceived(commandList[0], commandList[1]);
      serialBuffer = "";
  }

    if (!m_timer.isActive())
        m_timer.start(1000);
}

void SerialPortReader::handleTimeout()
{
    if (m_readData.isEmpty()) {
        m_standardOutput << QObject::tr("No data was currently available "
                                        "for reading from port %1 %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
    } else {
        m_standardOutput << QObject::tr("Data successfully received from port %1")
                           .arg(m_serialPort->portName())
                         << endl;
    }

    //QCoreApplication::quit();
}

void SerialPortReader::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    }
}
