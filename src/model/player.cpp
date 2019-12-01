#include <QPropertyAnimation>

#include "player.h"



namespace
{
constexpr double StepSize = 20.0;
constexpr int StepDuration = 200;
} // namespace



Player::Player(QObject* parent)
    : Item(parent)
{
    setSize(QSize(75, 35));
}

Player::~Player()
{
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
