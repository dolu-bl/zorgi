import QtQuick 2.0

import Zorgi 1.0
import Model 1.0



Rectangle
{
    id : root

    color: "black"

    PlayerView
    {
        id: playerView

        x: (root.width - width) / 2
        y: (root.height - height) / 2

        rotation: game.proxy().player().direction
    }

    Component.onCompleted:
    {
        var proxy = game.proxy();
        proxy.onViewSizeChanged(root.width, root.height);

        var playerProxy = proxy.playerProxy()
        playerView.onSizeChanged(playerProxy.size);
        playerProxy.sizeChanged.connect(playerView.onSizeChanged);

        for (var index = 0; index < proxy.proxyItemsQuantity(); ++index)
        {
            var proxyItem = proxy.proxyItem(index);
            if (null === proxyItem)
                continue;

            switch (proxyItem.type())
            {
            case ItemType.Asteroid:
                var asteroidView = Qt.createQmlObject('AsteroidView {}', root);
                if (null === asteroidView)
                    continue;

                asteroidView.onPositionChanged(proxyItem.position);
                asteroidView.onSizeChanged(proxyItem.size);
                asteroidView.visible = proxyItem.isVisible;
                proxyItem.positionChanged.connect(asteroidView.onPositionChanged);
                proxyItem.visibleChanged.connect(asteroidView.onVisibilityChanged);
                proxyItem.sizeChanged.connect(asteroidView.onSizeChanged);
                break;
            }
        }
    }

    onWidthChanged:
    {
        game.proxy().onViewSizeChanged(root.width, root.height);
    }

    onHeightChanged:
    {
        game.proxy().onViewSizeChanged(root.width, root.height);
    }
}
