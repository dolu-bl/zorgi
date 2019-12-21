import QtQuick 2.0
import QtQuick.Layouts 1.12

import Controls 1.0



Rectangle
{
    id : root

    width: 640
    height: 480
    color: styler.backgroundColor

    signal setRequested()
    signal backRequested()

    ColumnLayout
    {
        anchors.fill: parent
        spacing: root.height / 24

        Text
        {
            text: qsTr("settings")
            Layout.alignment: Qt.AlignHCenter
            height: parent.height / 3
            width: height * 2
            Layout.margins: parent.spacing
            color: styler.buttonsForegroundColor
            font
            {
                family: "Consolas"
                pointSize: 24
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        GameMenuCheckBox
        {
            text : qsTr("auto stabilization")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        GameMenuCheckBox
        {
            // TODO : place real setting
            text : qsTr("yet another setting")
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        GameMenuItem
        {
            text : qsTr("accept")
            Layout.fillWidth: true
            Layout.fillHeight: true
            onRequested: root.setRequested()
        }

        GameMenuItem
        {
            text : qsTr("back")
            Layout.fillWidth: true
            Layout.fillHeight: true
            onRequested: root.backRequested()
        }

        // TODO: Remove this text... once...
        Text
        {
            text: qsTr("=^..^=")
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#170942"
            font
            {
                family: "Consolas"
                pointSize: 24
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    } // ColumnLayout
}
