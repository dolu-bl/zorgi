import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Shapes 1.12
import QtQuick.Layouts 1.12



Window
{
    id : root

    visible: true
    width: 640
    height: 480
    title: qsTr("Zorgi")

    GridLayout
    {
        anchors.fill: parent
        flow: GridLayout.LeftToRight
        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#5d5b59"
        }
        SpaceView
        {
            id: spaceView
            Layout.fillHeight: true
            Layout.minimumWidth: height
        }
        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#5d5b59"
        }
    }

    Component.onCompleted:
    {
        root.showFullScreen();
    }
}
