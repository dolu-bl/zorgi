#include <QPropertyAnimation>
#include <QTime>

#include "player.h"



namespace
{
constexpr double StepSize = 20.0;
constexpr int StepDuration = 200;
constexpr int TurnDuration = 2000;
} // namespace



Player::Player(QObject* parent)
    : Item(parent)
{
    setSize(QSize(75, 35));
}

Player::~Player()
{
}



void Player::startTurn(const Qt::ArrowType direction)
{
    if (nullptr != m_currentAnimation)
        return;

    const int value = (Qt::LeftArrow == direction) ? -180 : 180;
    m_currentAnimation = new QPropertyAnimation(this, "direction");
    m_currentAnimation->setDuration(TurnDuration);
    m_currentAnimation->setStartValue(m_direction);
    m_currentAnimation->setEndValue(m_direction + value);
    m_currentAnimation->start();
}

void Player::stopTurn()
{
    if (nullptr == m_currentAnimation)
        return;

    m_currentAnimation->stop();
    m_currentAnimation->deleteLater();
    m_currentAnimation = nullptr;
}



void Player::moveLeft()
{
    auto animation = new QPropertyAnimation(this, "position");
    animation->setDuration(StepDuration);
    animation->setStartValue(m_position);
    animation->setEndValue(m_position - QVector2D(StepSize, 0));
    animation->start();
}

void Player::moveRight()
{
    auto animation = new QPropertyAnimation(this, "position");
    animation->setDuration(StepDuration);
    animation->setStartValue(m_position);
    animation->setEndValue(m_position + QVector2D(StepSize, 0));
    animation->start();
}

void Player::moveUp()
{
    auto animation = new QPropertyAnimation(this, "position");
    animation->setDuration(StepDuration);
    animation->setStartValue(m_position);
    animation->setEndValue(m_position - QVector2D(0, StepSize));
    animation->start();
}

void Player::moveDown()
{
    auto animation = new QPropertyAnimation(this, "position");
    animation->setDuration(StepDuration);
    animation->setStartValue(m_position);
    animation->setEndValue(m_position + QVector2D(0, StepSize));
    animation->start();
}
