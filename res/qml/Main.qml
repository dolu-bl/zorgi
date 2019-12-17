import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Shapes 1.12
import QtQuick.Layouts 1.12

import Zorgi 1.0
import Model 1.0
import Controls 1.0



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
        columnSpacing: 0

        LeftControlPanel
        {
            z: 10
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        SpaceView
        {
            z: 1
            id: spaceView
            width: height
            Layout.fillHeight: true
            Layout.minimumWidth: height
        }
        RightControlPanel
        {
            z: 10
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

    Game
    {
        id : game
    }

    KeyEmitter
    {
        id : keyEmitter
    }
}
