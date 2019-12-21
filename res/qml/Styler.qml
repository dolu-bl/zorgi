import QtQuick 2.0

// Main theme colors
// 2a1a5e
// f45905
// fb9224
// fbe555

QtObject
{
    // TODO : Add themes swicher
    // property bool isDarkTheme: false
    // readonly property color bordersColor: isDarkTheme ? "#111111" : "#aaaaaa"

    readonly property color bordersColor: "#fbe555"
    readonly property color backgroundColor: "#2a1a5e"

    readonly property color buttonsForegroundColor: "#fbe555"
    readonly property color buttonsBackgroundColor: "#2a1a5e"
    readonly property color buttonsBackgroundPressedColor: "#f45905"

    readonly property color menuItemColor: "#f45905"
    readonly property color menuItemSelectedColor: "#2a1a5e"
    readonly property color menuItemCheckColor: "#fb9224"
}
