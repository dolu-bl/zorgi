import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Shapes 1.12
import QtQuick.Layouts 1.12

import Zorgi 1.0



Window
{
    id : root

    visible: true
    width: 640
    height: 480
    title: qsTr("Zorgi")
    color: styler.bordersColor

    GridLayout
    {
        anchors.fill: parent
        flow: GridLayout.LeftToRight

        LeftControlPanel
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        SpaceView
        {
            id: spaceView
            Layout.fillHeight: true
            Layout.minimumWidth: height
        }
        RightControlPanel
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

    Component.onCompleted:
    {
        root.showFullScreen();
    }

    Styler
    {
        id: styler
    }

    KeyEmitter
    {
        id : keyEmitter
    }
}
