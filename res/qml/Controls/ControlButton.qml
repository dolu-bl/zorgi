import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4



Rectangle
{
    id: root
    property string text: ""
    property bool isPressed: tapHandler.pressed
    color: isPressed ? styler.buttonsBackgroundPressedColor : styler.buttonsBackgroundColor
    border.color: styler.buttonsForegroundColor
    border.width: 1
    height: 10
    width: 10
    radius: 5

    Text
    {
        id: text

        text: root.text

        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        font.bold: true
        font.pointSize: (root.height > 0) ? root.height * 0.33 : 1
        color: styler.buttonsForegroundColor

        anchors.centerIn: root
    }

    TapHandler
    {
        id: tapHandler
        acceptedModifiers: Qt.NoModifier
    }
}
