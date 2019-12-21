import QtQuick 2.0
import QtQuick.Layouts 1.12

import Zorgi 1.0
import Model 1.0
import Controls 1.0



Rectangle
{
    id : root

    width: 640
    height: 480

    GridLayout
    {
        anchors.fill: parent
        flow: GridLayout.LeftToRight
        columnSpacing: 0
        rowSpacing: 0

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
}
