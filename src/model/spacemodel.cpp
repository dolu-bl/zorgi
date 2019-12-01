#include <QDebug>
#include <QVariant>

#include "spacemodel.h"
#include "player.h"



SpaceModel::SpaceModel(QObject* parent)
    : QObject(parent)
    , m_player(new Player(this))
{
    connect(m_player, &Player::positionChanged, this, &SpaceModel::onPlayerPositionChanged);
}

SpaceModel::~SpaceModel()
{
}

Player* SpaceModel::player() const
{
    return m_player;
}

void SpaceModel::onPlayerPositionChanged(const QVector2D& position)
{
    Q_UNUSED(position)
    // TODO : do some thing
}
