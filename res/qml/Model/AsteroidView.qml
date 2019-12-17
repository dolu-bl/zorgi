import QtQuick 2.0
import QtQuick.Shapes 1.12



Shape
{
    id: root

    width: 50
    height: 50
    antialiasing: true

    Image
    {
        source: "/img/asteroid01.svg"
        width: parent.width
        height: parent.height
        sourceSize.width: width
        sourceSize.height: height
        anchors.fill: parent
    }

    function onPositionChanged(position)
    {
        root.x = position.x;
        root.y = position.y;
    }

    function onSizeChanged(size)
    {
        root.width = size.width;
        root.height = size.height;
    }

    function onVisibilityChanged(isVisible)
    {
        root.visible = isVisible
    }
}
