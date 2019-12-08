import QtQuick 2.0
import QtQuick.Layouts 1.12



Rectangle
{
    id: root
    color: styler.bordersColor

    GridLayout
    {
        id: grid
        columns: 3
        anchors.fill: parent

        ControlButton
        {
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "⭡"
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "⭠"
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "⭣"
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "⭢"
        }
        ControlButton
        {
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "⯌"
        }
    }
}
