import QtQuick 2.0
import QtQuick.Layouts 1.12



Rectangle
{
    id: root
    color: styler.bordersColor

    GridLayout
    {
        id: grid
        columns: 2
        anchors.fill: parent
        columnSpacing: 0
        rowSpacing: 0

        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▲"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_Up, isPressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "↶"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_Left, isPressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "↷"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_Right, isPressed)
        }
        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▼"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_Down, isPressed)
        }
        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "#"
        }
    }
}
