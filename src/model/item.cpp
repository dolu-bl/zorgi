#include <math.h>

#include "item.h"



Item::Item(QObject* parent)
    : QObject(parent)
{
}

Item::~Item()
{
}



QVector2D Item::position() const
{
    return m_position;
}

void Item::setPosition(const QVector2D& position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged(position);
}



QSize Item::size() const
{
    return m_size;
}

void Item::setSize(const QSize& size)
{
    if (m_size == size)
        return;

    m_size = size;
    emit sizeChanged(size);
}



float Item::direction() const
{
    return m_direction;
}

void Item::setDirection(const float direction)
{
    if (fabs(m_direction - direction) < std::numeric_limits<float>::epsilon())
        return;

    m_direction = direction;
    emit directionChanged(direction);
}
