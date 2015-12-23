#include <QApplication>
#include <QQmlApplicationEngine>
#include <QUdpSocket>
#include <QObject>
#include <QSignalMapper>
#include "MyTest.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    MyTest myTest;
    QObject *item = engine.rootObjects().at(0);
    //item->dumpObjectInfo();

    QObject::connect(item, SIGNAL(onButtonPress()), &myTest, SLOT(testIOT()));

    return app.exec();
}
