#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

#include "spacemodel.h"
#include "player.h"
#include "asteroid.h"



SpaceModel::SpaceModel(QObject* parent)
    : QObject(parent)
    , m_mainTimer(new QTimer(this))
{
    setObjectName("SpaceModelInstance");
    fillData();
    connect(m_mainTimer, &QTimer::timeout, this, &SpaceModel::onMainTimer);
    m_mainTimer->start(100);
}

SpaceModel::~SpaceModel()
{
}



int SpaceModel::itemsCount() const
{
    return m_items.size();
}

Item* SpaceModel::item(int i) const
{
    if (m_items.size() <= i || 0 > i)
        return nullptr;

    return m_items.at(i);
}

QVector<Item*> SpaceModel::items() const
{
    return m_items;
}



QVector<Player*> SpaceModel::players() const
{
    QVector<Player*> result;
    for (auto item : m_items)
    {
        if (auto player = qobject_cast<Player*>(item))
            result.append(player);
    }
    return result;
}



void SpaceModel::onMainTimer()
{
    for (auto item : m_items)
        item->updateAnamation();

    // TODO : Add world events here
}



void SpaceModel::fillData()
{
    auto player = new Player(this);
    player->setPosition(QVector2D(0, 0));
    m_items.append(player);

    {
        auto asteroid = new Asteroid();
        asteroid->setPosition(QVector2D(200, 200));
        m_items.append(asteroid);
    }
    {
        auto asteroid = new Asteroid();
        asteroid->setPosition(QVector2D(-200, 200));
        m_items.append(asteroid);
    }
    {
        auto asteroid = new Asteroid();
        asteroid->setPosition(QVector2D(200, -200));
        m_items.append(asteroid);
    }
    {
        auto asteroid = new Asteroid();
        asteroid->setPosition(QVector2D(-200, -200));
        m_items.append(asteroid);
    }

    QRandomGenerator generator(108);
    for (int i = 0; i < 1000; ++i)
    {
        auto asteroid = new Asteroid();
        const int x = generator.bounded(-2000, 2000);
        const int y = generator.bounded(-2000, 2000);
        const QVector2D position(x, y);
        if (300 > position.distanceToPoint(player->position()))
            continue;

        asteroid->setPosition(position);
        m_items.append(asteroid);
    }
}
