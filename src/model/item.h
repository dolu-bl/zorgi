#pragma once

#include <QSize>
#include <QObject>
#include <QVector2D>

#include "itemtype.h"
#include "misc/directiontype.h"

class QPropertyAnimation;



class Item : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVector2D position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(float direction READ direction WRITE setDirection NOTIFY directionChanged)

public:
    explicit Item(QObject* parent = nullptr);
    virtual ~Item() override;

public:
    virtual ItemType::Type type() const;

    virtual QVector2D position() const;
    virtual void setPosition(const QVector2D& position);

    /// Returns point in the center of the size, not excluding position offset.
    virtual QVector2D sizeCenter() const;

    virtual QSize size() const;
    virtual void setSize(const QSize& size);

    virtual float direction() const;
    virtual void setDirection(const float direction);

public:
    void startMove(const Qt::ArrowType arrowType);
    void stopMove(const Qt::ArrowType arrowType);

    void startTurn(const Qt::ArrowType arrowType);
    void stopTurn();

    virtual void updateAnamation();

signals:
    void positionChanged(const QVector2D& position) const;
    void sizeChanged(const QSize& size) const;
    void directionChanged(const float direction) const;

protected:
    QVector2D m_position;
    QSize m_size;
    float m_direction = 0;

private:
    DirectionType m_moveIntention = DirectionType::Naught;
    DirectionType m_turnIntention = DirectionType::Naught;

    QPropertyAnimation* m_moveAnimation;
    QPropertyAnimation* m_turnAnimation;

};
