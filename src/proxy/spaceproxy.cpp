#include "model/spacemodel.h"
#include "model/player.h"

#include "proxy/proxyitem.h"

#include "spaceproxy.h"


namespace
{
constexpr int DefaultViewWidth = 480;
constexpr int DefaultViewBorder = 50;
} // namespace



SpaceProxy::SpaceProxy(QObject* parent)
    : QObject(parent)
{
    setObjectName("SpaceProxyInstance");
}

SpaceProxy::~SpaceProxy()
{
}



void SpaceProxy::setModel(SpaceModel* model)
{
    m_model = model;

    if (nullptr == m_model)
        return;

    const auto players = m_model->players();
    m_player = players.value(0, nullptr);
    Q_ASSERT(nullptr != m_player);

    connect(m_player, &Player::positionChanged, this, &SpaceProxy::playerPositionChanged, Qt::UniqueConnection);
    connect(m_player, &Player::directionChanged, this, &SpaceProxy::playerDirectionChanged, Qt::UniqueConnection);

    for (const auto item : m_model->items())
    {
        auto proxyItem = new ProxyItem(this);
        proxyItem->setProxy(this);
        proxyItem->subscribe(item);
        m_proxyItems.append(proxyItem);
    }
}

SpaceModel* SpaceProxy::model() const
{
    return m_model;
}



QVector2D SpaceProxy::mapFromModel(const QVector2D& position) const
{
    if (nullptr == m_player)
        return QVector2D();

    const QVector2D relativePosition = m_player->position() - m_player->sizeCenter() - position;
    return (relativePosition * m_viewScaleFactor + m_viewCenter);
}

QSize SpaceProxy::mapFromModel(const QSize& size) const
{
    return (size * double(m_viewScaleFactor));
}



QVector2D SpaceProxy::mapToModel(const QVector2D& position) const
{
    Q_UNUSED(position)
    // TODO : write content
    return QVector2D();
}

QSize SpaceProxy::mapToModel(const QSize& size) const
{
    Q_UNUSED(size)
    // TODO : write content
    return QSize();
}



int SpaceProxy::proxyItemsQuantity() const
{
    return m_proxyItems.size();
}

ProxyItem* SpaceProxy::proxyItem(const int index) const
{
    return m_proxyItems.value(index, nullptr);
}



Player* SpaceProxy::player() const
{
    return m_player;
}

ProxyItem* SpaceProxy::playerProxy() const
{
    // TODO : Need another way to take playerProxy
    for (auto proxyItem : m_proxyItems)
    {
        if (ItemType::Player == proxyItem->type())
            return proxyItem;
    }
    return nullptr;
}



QSize SpaceProxy::viewSize() const
{
    return m_viewSize;
}

void SpaceProxy::setViewSize(const QSize& size)
{
    if (size == m_viewSize)
        return;

    m_viewSize = size;
    m_viewScaleFactor = size.width() / DefaultViewWidth;
    m_viewCenter = QVector2D(size.width() * 0.5f, size.height() * 0.5f);

    emit viewSizeChanged(size);
}



QRect SpaceProxy::visibleItemsRect() const
{
    const int border = int(DefaultViewBorder * m_viewScaleFactor);
    return QRect(-border, -border, m_viewSize.width() + border, m_viewSize.height() + border);
}



void SpaceProxy::onViewSizeChanged(const int width, const int height)
{
    setViewSize(QSize(width, height));
}
