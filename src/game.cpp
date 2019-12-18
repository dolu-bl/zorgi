#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/spacemodel.h"
#include "model/itemtype.h"
#include "model/player.h"
#include "model/asteroid.h"

#include "proxy/spaceproxy.h"
#include "proxy/proxyitem.h"

#include "misc/keyemitter.h"

#include "game.h"

QQmlApplicationEngine* Game::m_engine = nullptr;



void Game::registerQmlTypes()
{
    qmlRegisterType<Game>("Zorgi", 1, 0, "Game");
    qmlRegisterType<SpaceModel>("Zorgi", 1, 0, "SpaceModel");
    qmlRegisterType<SpaceProxy>("Zorgi", 1, 0, "SpaceProxy");
    qmlRegisterType<Item>("Zorgi", 1, 0, "Item");
    qmlRegisterType<Player>("Zorgi", 1, 0, "Player");
    qmlRegisterType<Asteroid>("Zorgi", 1, 0, "Asteroid");
    qmlRegisterType<ProxyItem>("Zorgi", 1, 0, "ProxyItem");
    qmlRegisterType<KeyEmitter>("Zorgi", 1, 0, "KeyEmitter");
    qmlRegisterUncreatableMetaObject(ItemType::staticMetaObject, "Zorgi", 1, 0, "ItemType", "Error: only enums");
}

void Game::init()
{
    if (nullptr != m_engine)
        return;

    Game::registerQmlTypes();

    m_engine = new QQmlApplicationEngine();
    m_engine->addImportPath(":/qml");
    m_engine->load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
}

Game* Game::gameFromQml()
{
    for (const auto rootObject : m_engine->rootObjects())
    {
        if (auto game = rootObject->findChild<Game*>("GameInstance"))
            return game;
    }
    return nullptr;
}

Game::Game(QObject* parent)
    : QObject(parent)
    , m_model(nullptr)
    , m_proxy(nullptr)
{
    setObjectName("GameInstance");
    m_model = new SpaceModel(this);
    m_proxy = new SpaceProxy(this);
    m_proxy->setModel(m_model);
    QCoreApplication::instance()->installEventFilter(this);
}

Game::~Game()
{
}

bool Game::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() == QEvent::KeyPress)
        return keyPressEventFilter(watched, dynamic_cast<QKeyEvent*>(event));

    if (event->type() == QEvent::KeyRelease)
        return keyReleaseEventFilter(watched, dynamic_cast<QKeyEvent*>(event));

    return QObject::eventFilter(watched, event);
}

SpaceModel* Game::model() const
{
    return m_model;
}

SpaceProxy* Game::proxy() const
{
    return m_proxy;
}



bool Game::keyPressEventFilter(QObject* watched, QKeyEvent* event)
{
    if (nullptr == event || event->isAutoRepeat())
        return QObject::eventFilter(watched, event);

    auto player = m_proxy->player();
    switch (event->key())
    {
    case Qt::Key_Left:
        player->startTurn(Qt::LeftArrow);
        return true;

    case Qt::Key_Right:
        player->startTurn(Qt::RightArrow);
        return true;

    case Qt::Key_W:
    case Qt::Key_Up:
        player->startMove(Qt::UpArrow);
        return true;

    case Qt::Key_S:
    case Qt::Key_Down:
        player->startMove(Qt::DownArrow);
        return true;

    case Qt::Key_A:
        player->startMove(Qt::LeftArrow);
        return true;

    case Qt::Key_D:
        player->startMove(Qt::RightArrow);
        return true;

    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}

bool Game::keyReleaseEventFilter(QObject* watched, QKeyEvent* event)
{
    if (nullptr == event || event->isAutoRepeat())
        return QObject::eventFilter(watched, event);

    auto player = m_proxy->player();
    switch (event->key())
    {
    case Qt::Key_Left:
    case Qt::Key_Right:
        player->stopTurn();
        return true;

    case Qt::Key_W:
    case Qt::Key_Up:
        player->stopMove(Qt::UpArrow);
        return true;

    case Qt::Key_S:
    case Qt::Key_Down:
        player->stopMove(Qt::DownArrow);
        return true;

    case Qt::Key_A:
        player->stopMove(Qt::LeftArrow);
        return true;

    case Qt::Key_D:
        player->stopMove(Qt::RightArrow);
        return true;

    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}
