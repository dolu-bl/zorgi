#include <QDebug>
#include <QPropertyAnimation>

#include <math.h>

#include "item.h"



Item::Item(QObject* parent)
    : QObject(parent)
    , m_moveAnimation(new QPropertyAnimation(this, "position"))
    , m_turnAnimation(new QPropertyAnimation(this, "direction"))
{
}

Item::~Item()
{
}



ItemType::Type Item::type() const
{
    return ItemType::Invalid;
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



QVector2D Item::sizeCenter() const
{
    return QVector2D(m_size.width() * 0.5f, m_size.height() * 0.5f);
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



// TODO : Refactoring required
void Item::startMove(const Qt::ArrowType arrowType)
{
    switch (arrowType)
    {
    case Qt::UpArrow:
        if (DirectionType::Left == m_moveIntention)
        {
            m_moveIntention = DirectionType::ForwardLeft;
        }
        else if (DirectionType::Right == m_moveIntention)
        {
            m_moveIntention = DirectionType::ForwardRight;
        }
        else
        {
            m_moveIntention = DirectionType::Forward;
        }
        break;

    case Qt::RightArrow:
        if (DirectionType::Forward == m_moveIntention)
        {
            m_moveIntention = DirectionType::ForwardRight;
        }
        else if (DirectionType::Backward == m_moveIntention)
        {
            m_moveIntention = DirectionType::BackwardRight;
        }
        else
        {
            m_moveIntention = DirectionType::Right;
        }
        break;

    case Qt::DownArrow:
        if (DirectionType::Left == m_moveIntention)
        {
            m_moveIntention = DirectionType::BackwardLeft;
        }
        else if (DirectionType::Right == m_moveIntention)
        {
            m_moveIntention = DirectionType::BackwardRight;
        }
        else
        {
            m_moveIntention = DirectionType::Backward;
        }
        break;

    case Qt::LeftArrow:
        if (DirectionType::Forward == m_moveIntention)
        {
            m_moveIntention = DirectionType::ForwardLeft;
        }
        else if (DirectionType::Backward == m_moveIntention)
        {
            m_moveIntention = DirectionType::BackwardLeft;
        }
        else
        {
            m_moveIntention = DirectionType::Left;
        }
        break;

    default:
        break;
    }
}

// TODO : Refactoring required
void Item::stopMove(const Qt::ArrowType arrowType)
{
    switch (arrowType)
    {
    case Qt::UpArrow:
        if (DirectionType::ForwardLeft == m_moveIntention)
        {
            m_moveIntention = DirectionType::Left;
        }
        else if (DirectionType::ForwardRight == m_moveIntention)
        {
            m_moveIntention = DirectionType::Right;
        }
        else
        {
            m_moveIntention = DirectionType::Naught;
        }
        break;

    case Qt::RightArrow:
        if (DirectionType::ForwardRight == m_moveIntention)
        {
            m_moveIntention = DirectionType::Forward;
        }
        else if (DirectionType::BackwardRight == m_moveIntention)
        {
            m_moveIntention = DirectionType::Backward;
        }
        else
        {
            m_moveIntention = DirectionType::Naught;
        }
        break;

    case Qt::DownArrow:
        if (DirectionType::BackwardLeft == m_moveIntention)
        {
            m_moveIntention = DirectionType::Left;
        }
        else if (DirectionType::BackwardRight == m_moveIntention)
        {
            m_moveIntention = DirectionType::Right;
        }
        else
        {
            m_moveIntention = DirectionType::Naught;
        }
        break;

    case Qt::LeftArrow:
        if (DirectionType::ForwardLeft == m_moveIntention)
        {
            m_moveIntention = DirectionType::Forward;
        }
        else if (DirectionType::BackwardLeft == m_moveIntention)
        {
            m_moveIntention = DirectionType::Backward;
        }
        else
        {
            m_moveIntention = DirectionType::Naught;
        }
        break;

    default:
        break;
    }
}

void Item::startTurn(const Qt::ArrowType arrowType)
{
    switch (arrowType)
    {
    case Qt::LeftArrow:
        m_turnIntention = DirectionType::Left;
        break;

    case Qt::RightArrow:
        m_turnIntention = DirectionType::Right;
        break;

    default:
        m_turnIntention = DirectionType::Naught;
        break;
    }
}

void Item::stopTurn()
{
    m_turnIntention = DirectionType::Naught;
}



// TODO : Refactoring required
void Item::updateAnamation()
{
    const auto direction = -m_direction * float(M_PI) / 180.0f;

    // TODO : There is no place for speed constant
    static const float Speed = 20.0f;
    static const float Speed2 = Speed / 2;

    QVector2D offset;
    switch (m_moveIntention)
    {
    case DirectionType::ForwardLeft:
        offset = QVector2D(Speed2 * cos(direction), -Speed2 * sin(direction)) +
                 QVector2D(Speed2 * sin(direction), Speed2 * cos(direction));
        break;

    case DirectionType::Forward:
        offset = QVector2D(Speed * sin(direction), Speed * cos(direction));
        break;

    case DirectionType::ForwardRight:
        offset = QVector2D(-Speed2 * cos(direction), Speed2 * sin(direction)) +
                 QVector2D(Speed2 * sin(direction), Speed2 * cos(direction));
        break;

    case DirectionType::Right:
        offset = QVector2D(-Speed * cos(direction), Speed * sin(direction));
        break;

    case DirectionType::BackwardRight:
        offset = QVector2D(-Speed2 * cos(direction), Speed2 * sin(direction)) +
                 QVector2D(-Speed * sin(direction), -Speed * cos(direction));
        break;

    case DirectionType::Backward:
        offset = QVector2D(-Speed * sin(direction), -Speed * cos(direction));
        break;

    case DirectionType::BackwardLeft:
        offset = QVector2D(Speed * cos(direction), -Speed * sin(direction)) +
                 QVector2D(-Speed * sin(direction), -Speed * cos(direction));
        break;

    case DirectionType::Left:
        offset = QVector2D(Speed * cos(direction), -Speed * sin(direction));
        break;

    default:
        break;
    }

    if (!offset.isNull())
    {
        m_moveAnimation->stop();
        m_moveAnimation->setDuration(100);
        m_moveAnimation->setStartValue(m_position);
        m_moveAnimation->setEndValue(m_position + offset);
        m_moveAnimation->start();
    }

    float directionOffset = 0.0;
    switch (m_turnIntention)
    {
    case DirectionType::Left:
        directionOffset = -10.0;
        break;

    case DirectionType::Right:
        directionOffset = 10.0;
        break;

    default:
        break;
    }

    if (abs(directionOffset) > 0.1f)
    {
        m_turnAnimation->stop();
        m_turnAnimation->setDuration(100);
        m_turnAnimation->setStartValue(m_direction);
        m_turnAnimation->setEndValue(m_direction + directionOffset);
        m_turnAnimation->start();
    }
}
