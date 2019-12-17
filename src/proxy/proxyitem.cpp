#include <QRect>
#include <QDebug>

#include "model/item.h"
#include "spaceproxy.h"

#include "proxyitem.h"



ProxyItem::ProxyItem(QObject* parent)
    : QObject(parent)
{
}

ProxyItem::~ProxyItem()
{
}



void ProxyItem::setProxy(const SpaceProxy* proxy)
{
    m_proxy = proxy;

    if (nullptr == proxy)
        return;

    connect(proxy, &SpaceProxy::playerPositionChanged, this, &ProxyItem::onPlayerPositionChanged, Qt::UniqueConnection);
    connect(proxy, &SpaceProxy::playerDirectionChanged, this, &ProxyItem::onPlayerDirectionChanged, Qt::UniqueConnection);
    connect(proxy, &SpaceProxy::viewSizeChanged, this, &ProxyItem::onViewSizeChanged, Qt::UniqueConnection);
}

void ProxyItem::subscribe(const Item* item)
{
    m_item = item;

    if (nullptr == item)
        return;

    connect(item, &Item::positionChanged, this, &ProxyItem::onPositionChanged, Qt::UniqueConnection);
}



// TODO : Solve the problem with transferring the ItemType::Type enumeration to QML
int ProxyItem::type() const
{
    if (m_item.isNull())
        return int(ItemType::Invalid);

    return int(m_item->type());
}

QVector2D ProxyItem::position() const
{
    if (m_item.isNull() || m_proxy.isNull())
        return QVector2D();

    return m_proxy->mapFromModel(m_item->position());
}

QSize ProxyItem::size() const
{
    if (m_item.isNull() || m_proxy.isNull())
        return QSize();

    return m_proxy->mapFromModel(m_item->size());
}

float ProxyItem::direction() const
{
    return 0.0;
}



void ProxyItem::setVisible(const bool isVisible)
{
    if (isVisible == m_isVisible)
        return;

    m_isVisible = isVisible;
    emit visibleChanged(isVisible);
}

bool ProxyItem::isVisible() const
{
    return m_isVisible;
}



void ProxyItem::onPositionChanged(const QVector2D& position)
{
    Q_UNUSED(position)
    reinitPosition();
}

void ProxyItem::onPlayerPositionChanged(const QVector2D& position)
{
    Q_UNUSED(position)
    reinitPosition();
}

void ProxyItem::onPlayerDirectionChanged(const float direction)
{
    Q_UNUSED(direction)
    // TODO: It is posible to rotate the whole view, not the ship..
}

void ProxyItem::onViewSizeChanged(const QSize& viewSize)
{
    Q_UNUSED(viewSize)
    emit sizeChanged(this->size());
    reinitPosition();
}


void ProxyItem::reinitPosition()
{
    const auto visibleItemsRect = m_proxy->visibleItemsRect();
    if (!visibleItemsRect.isValid())
        return;

    const auto proxyItemPosition = this->position();
    if (!visibleItemsRect.contains( int(proxyItemPosition.x()) ,
                                    int(proxyItemPosition.y()) ))
    {
        setVisible(false);
        return;
    }

    setVisible(true);
    emit positionChanged(proxyItemPosition);
}
