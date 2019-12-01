#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model\spacemodel.h"
#include "model\player.h"



int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<SpaceModel>("Zorgi", 1, 0, "SpaceModel");
    qmlRegisterType<Player>("Zorgi", 1, 0, "Player");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
