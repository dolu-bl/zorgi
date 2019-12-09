#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/spacemodel.h"
#include "model/player.h"
#include "misc/keyemitter.h"



int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<SpaceModel>("Zorgi", 1, 0, "SpaceModel");
    qmlRegisterType<Player>("Zorgi", 1, 0, "Player");
    qmlRegisterType<KeyEmitter>("Zorgi", 1, 0, "KeyEmitter");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // Event filter installation to instance of SpaceModel.
    for (auto rootObject : engine.rootObjects())
    {
        auto spaceModel = rootObject->findChild<SpaceModel*>("SpaceModelInstance");
        if (nullptr == spaceModel)
            continue;

        app.installEventFilter(spaceModel);
        break;
    }

    return app.exec();
}
