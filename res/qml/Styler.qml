import QtQuick 2.0

QtObject
{
    property bool isDarkTheme: false

    readonly property color bordersColor: isDarkTheme ? "#111111" : "#aaaaaa"

    readonly property color buttonsForegroundColor: isDarkTheme ? "#111111" : "#aaaaaa"
    readonly property color buttonsBackgroundColor: isDarkTheme ? "#adaba9" : "#5d5b59"
    readonly property color buttonsBackgroundPressedColor: isDarkTheme ? "#5d5b59" : "#adaba9"
}
