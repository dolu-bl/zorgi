#include <QGuiApplication>

#include "game.h"



int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication application(argc, argv);
    Game::init();
    return application.exec();
}
