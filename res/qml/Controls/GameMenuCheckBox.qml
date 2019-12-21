import QtQuick 2.0
import QtQuick.Controls 2.12

import Controls 1.0



Rectangle
{
    id: root

    width: 400
    height: 70

    color: styler.buttonsBackgroundColor

    property alias text: textLabel.text
    property alias value: checkBox.checked

    Rectangle
    {
        anchors.centerIn: parent
        color: root.isPressed ? styler.buttonsBackgroundPressedColor : styler.buttonsBackgroundColor
        width: 400
        height: 70

        border.color: styler.buttonsForegroundColor
        border.width: root.isSelected? 4 : 0

        CheckBox
        {
            id: checkBox
            indicator: Rectangle
            {
                id: indicator
                implicitWidth: 64
                implicitHeight: 64
                radius: 4
                border.color: styler.menuItemColor
                border.width: 4
                color: root.color

                Text
                {
                    visible: checkBox.checked
                    text: "X"
                    color: styler.menuItemCheckColor

                    font
                    {
                        family: "Consolas"
                        pointSize: 42
                    }

                    anchors.margins: 4
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                } // Text
            } // Rectangle

            contentItem: Text
            {
                id: textLabel
                anchors.leftMargin: 10
                anchors.left: indicator.right
                color: root.isPressed ? styler.menuItemSelectedColor : styler.menuItemColor

                font
                {
                    family: "Consolas"
                    pointSize: 24
                }

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            } // Text

        } // CheckBox
    } // Rectangle
}
