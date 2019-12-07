import QtQuick 2.0
import Zorgi 1.0


Rectangle
{
    id : root

    color: "black"

    PlayerView
    {
        id: playerView

        x: (root.width - width) / 2
        y: (root.height - height) / 2

        width: spaceModel.player().size.width
        height: spaceModel.player().size.height
        rotation: spaceModel.player().direction
    }

    SpaceModel
    {
        id: spaceModel
    }
}
