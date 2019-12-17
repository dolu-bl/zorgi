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

        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▲"
            onPressedChanged: keyEmitter.emitKey(Qt.Key_Up, pressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "↶"
            onPressedChanged: keyEmitter.emitKey(Qt.Key_Left, pressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "↷"
            onPressedChanged: keyEmitter.emitKey(Qt.Key_Right, pressed)
        }
        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▼"
            onPressedChanged: keyEmitter.emitKey(Qt.Key_Down, pressed)
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
