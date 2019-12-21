import QtQuick 2.0
import QtQuick 2.12



Rectangle
{
    id: root

    width: 400
    height: 70

    color: styler.buttonsBackgroundColor

    property alias text: textLabel.text

    property bool isPressed: tapHandler.pressed || mouseArea.pressed
    property bool isSelected: mouseArea.containsMouse

    signal requested()

    onIsPressedChanged: function()
    {
        if (!isPressed)
            root.requested()
    }

    Rectangle
    {
        anchors.centerIn: parent
        color: root.isPressed ? styler.buttonsBackgroundPressedColor : styler.buttonsBackgroundColor
        width: 400
        height: 70

        border.color: styler.buttonsForegroundColor
        border.width: root.isSelected? 4 : 0

        Text
        {
            id: textLabel
            color: root.isPressed ? styler.menuItemSelectedColor : styler.menuItemColor
            anchors.centerIn: parent

            font
            {
                family: "Consolas"
                pointSize: 24
            }

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    TapHandler
    {
        id: tapHandler
        acceptedModifiers: Qt.NoModifier
    }

    MouseArea
    {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
    }

}
