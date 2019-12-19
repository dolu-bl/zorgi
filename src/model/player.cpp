#include <QDebug>
#include <QPropertyAnimation>
#include <QTime>

#include "player.h"



Player::Player(QObject* parent)
    : Item(parent)
{
    setSize(QSize(75, 35));
}

Player::~Player()
{
}



ItemType::Type Player::type() const
{
    return ItemType::Player;
}
