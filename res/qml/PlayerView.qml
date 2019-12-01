import QtQuick 2.0
import QtQuick.Shapes 1.12

import Zorgi 1.0


Shape
{
    id: root

    width: 75
    height: 50
    antialiasing: true

    Image
    {
        source: "/img/ship01.svg"
        width: parent.width
        height: parent.height
        sourceSize.width: width
        sourceSize.height: height
        anchors.fill: parent
    }
}
