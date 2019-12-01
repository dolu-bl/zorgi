import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Shapes 1.12



Window
{
    id : root

    visible: true
    width: 640
    height: 480
    title: qsTr("Zorgi")

    SpaceView
    {
        id: spaceView
        anchors.fill: parent
    }

    Component.onCompleted:
    {
        root.showFullScreen();
    }
}
