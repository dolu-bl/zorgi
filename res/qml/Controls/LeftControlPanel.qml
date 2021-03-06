import QtQuick 2.0
import QtQuick.Layouts 1.12


Rectangle
{
    id: root
    color: styler.backgroundColor

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
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_W, isPressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "◀"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_A, isPressed)
        }
        ControlButton
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▶"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_D, isPressed)
        }
        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "▼"
            onIsPressedChanged: keyEmitter.emitKey(Qt.Key_S, isPressed)
        }
        ControlButton
        {
            Layout.columnSpan: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "*"
        }
    }
}
