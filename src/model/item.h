#pragma once

#include <QSize>
#include <QObject>
#include <QVector2D>



class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector2D position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY sizeChanged)

public:
    explicit Item(QObject* parent = nullptr);
    virtual ~Item() override;

public:
    virtual QVector2D position() const;
    virtual void setPosition(const QVector2D& position);

    virtual QSize size() const;
    virtual void setSize(const QSize& size);

signals:
    void positionChanged(const QVector2D& position);
    void sizeChanged(const QSize& size);

protected:
    QVector2D m_position;
    QSize m_size;

};
