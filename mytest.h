#include <QObject>
#include <QUdpSocket>
#ifndef MYTEST_H
#define MYTEST_H


class MyTest : public QObject
{
    Q_OBJECT

private:
    QUdpSocket *udpSocket;

public slots:
    void testIOT();
    void readPendingDatagrams();
public:
    void initSocket();
};

#endif // MYTEST_H
