#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QVariant>

#include "spacemodel.h"
#include "player.h"



SpaceModel::SpaceModel(QObject* parent)
    : QObject(parent)
    , m_player(new Player(this))
{
    setObjectName("SpaceModelInstance");
    connect(m_player, &Player::positionChanged, this, &SpaceModel::onPlayerPositionChanged);
}

SpaceModel::~SpaceModel()
{
}

Player* SpaceModel::player() const
{
    return m_player;
}

bool SpaceModel::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() == QEvent::KeyPress)
        return keyPressEventFilter(watched, dynamic_cast<QKeyEvent*>(event));

    if (event->type() == QEvent::KeyRelease)
        return keyReleaseEventFilter(watched, dynamic_cast<QKeyEvent*>(event));

    return QObject::eventFilter(watched, event);
}

void SpaceModel::onPlayerPositionChanged(const QVector2D& position)
{
    Q_UNUSED(position)
    // TODO : do some thing
}

bool SpaceModel::keyPressEventFilter(QObject* watched, QKeyEvent* event)
{
    if (nullptr == event || event->isAutoRepeat())
        return QObject::eventFilter(watched, event);

    switch (event->key())
    {
    case Qt::Key_Left:
        m_player->moveLeft();
        return true;

    case Qt::Key_Right:
        m_player->moveRight();
        return true;

    case Qt::Key_W:
    case Qt::Key_Up:
        m_player->moveUp();
        return true;

    case Qt::Key_S:
    case Qt::Key_Down:
        m_player->moveDown();
        return true;

    case Qt::Key_A:
        m_player->startTurn(Qt::LeftArrow);
        return true;

    case Qt::Key_D:
        m_player->startTurn(Qt::RightArrow);
        return true;

    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}

bool SpaceModel::keyReleaseEventFilter(QObject* watched, QKeyEvent* event)
{
    if (nullptr == event || event->isAutoRepeat())
        return QObject::eventFilter(watched, event);

    switch (event->key())
    {
    case Qt::Key_A:
    case Qt::Key_D:
        m_player->stopTurn();
        return true;

    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}

