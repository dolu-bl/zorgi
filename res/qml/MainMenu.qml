import QtQuick 2.0
import QtQuick.Layouts 1.12

import Controls 1.0



Rectangle
{
    id : root

    width: 640
    height: 480
    color: styler.backgroundColor

    signal startRequested()
    signal settingsRequested()

    ColumnLayout
    {
        anchors.fill: parent
        spacing: root.height / 24

        Image
        {
            Layout.alignment: Qt.AlignHCenter
            height: parent.height / 3
            width: height * 2
            Layout.margins: parent.spacing
            sourceSize.width: width
            sourceSize.height: height
            source: "/img/zorgi.svg"
        }

        GameMenuItem
        {
            text : qsTr("start")
            Layout.fillWidth: true
            Layout.fillHeight: true
            onRequested: root.startRequested()
        }

        GameMenuItem
        {
            text : qsTr("settings")
            Layout.fillWidth: true
            Layout.fillHeight: true
            onRequested: root.settingsRequested()
        }

        GameMenuItem
        {
            text : qsTr("quit")
            Layout.fillWidth: true
            Layout.fillHeight: true
            onRequested: Qt.quit()
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
