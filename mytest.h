#include <QObject>
#ifndef MYTEST_H
#define MYTEST_H


class MyTest : public QObject
{
    Q_OBJECT
public slots:
    void testIOT();
};

#endif // MYTEST_H
