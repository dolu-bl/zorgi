import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4



Button
{
    id: root

    style: ButtonStyle
    {
        label: Text
        {
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.Fit
            minimumPixelSize: 10
            font.pixelSize: 720
            color: styler.buttonsForegroundColor
            text: root.text
        }
        background: Rectangle
        {
            color: control.pressed ? styler.buttonsBackgroundPressedColor : styler.buttonsBackgroundColor
            radius: 4
        }
    }
}
