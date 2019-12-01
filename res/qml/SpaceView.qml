import QtQuick 2.0
import Zorgi 1.0


Rectangle
{
    id : root

    color: "black"

    PlayerView
    {
        id: playerView

        x: spaceModel.player().position.x
        y: spaceModel.player().position.y

        width: spaceModel.player().size.width
        height: spaceModel.player().size.height

        focus: true
        Keys.onLeftPressed: spaceModel.player().moveLeft()
        Keys.onRightPressed: spaceModel.player().moveRight()
        Keys.onUpPressed: spaceModel.player().moveUp()
        Keys.onDownPressed: spaceModel.player().moveDown()
    }

    SpaceModel
    {
        id: spaceModel
    }
}
