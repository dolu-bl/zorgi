#pragma once

#include <QSize>
#include <QRect>
#include <QObject>
#include <QVector2D>

class QEvent;
class QKeyEvent;

class SpaceModel;
class Player;
class ProxyItem;



class SpaceProxy : public QObject
{
    Q_OBJECT

public:
    explicit SpaceProxy(QObject* parent = nullptr);
    virtual ~SpaceProxy() override;

public:
    void setModel(SpaceModel* model);
    SpaceModel* model() const;

    QVector2D mapFromModel(const QVector2D& position) const;
    QSize mapFromModel(const QSize& size) const;

    QVector2D mapToModel(const QVector2D& position) const;
    QSize mapToModel(const QSize& size) const;

    Q_INVOKABLE int proxyItemsQuantity() const;
    Q_INVOKABLE ProxyItem* proxyItem(const int index) const;

    Q_INVOKABLE Player* player() const;
    Q_INVOKABLE ProxyItem* playerProxy() const;

    Q_INVOKABLE QSize viewSize() const;
    Q_INVOKABLE void setViewSize(const QSize& size);

    QRect visibleItemsRect() const;

signals:
    void playerPositionChanged(const QVector2D& position);
    void playerDirectionChanged(const float& direction);
    void viewSizeChanged(const QSize& viewSize);

public slots:
    void onViewSizeChanged(const int width, const int height);

private:
    SpaceModel* m_model = nullptr;
    Player* m_player = nullptr;
    QVector<ProxyItem*> m_proxyItems;

    QSize m_viewSize;
    float m_viewScaleFactor = 1.0f;
    QVector2D m_viewCenter;

};
