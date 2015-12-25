#include <QObject>
#include <QDebug>
#include <QUdpSocket>
#include "mytest.h"


void MyTest::testIOT() {
    qDebug() << "test!" << endl;
    if(udpSocket == NULL) initSocket();

}

void MyTest::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 3479);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

void MyTest::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);

        //processTheDatagram(datagram);
        qDebug() << datagram.data();
    }
}
