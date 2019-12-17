#pragma once

#include <QSize>
#include <QObject>
#include <QPointer>
#include <QVector2D>

class Item;
class SpaceProxy;



class ProxyItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVector2D position READ position NOTIFY positionChanged)
    Q_PROPERTY(QSize size READ size NOTIFY sizeChanged)
    Q_PROPERTY(float direction READ direction NOTIFY directionChanged)
    Q_PROPERTY(bool isVisible READ isVisible NOTIFY visibleChanged)

public:
    explicit ProxyItem(QObject* parent = nullptr);
    virtual ~ProxyItem() override;

    void setProxy(const SpaceProxy* proxy);
    void subscribe(const Item* item);

    Q_INVOKABLE virtual int type() const;
    virtual QVector2D position() const;
    virtual QSize size() const;
    virtual float direction() const;

    void setVisible(const bool isVisible);
    bool isVisible() const;

signals:
    void positionChanged(const QVector2D& position) const;
    void sizeChanged(const QSize& size) const;
    void directionChanged(const float direction) const;
    void visibleChanged(const bool isVisible) const;

private slots:
    void onPositionChanged(const QVector2D& position);
    void onPlayerPositionChanged(const QVector2D& position);
    void onPlayerDirectionChanged(const float direction);
    void onViewSizeChanged(const QSize& viewSize);

private:
    void reinitPosition();

private:
    QPointer<const Item> m_item;
    QPointer<const SpaceProxy> m_proxy;
    bool m_isVisible = true;

};
