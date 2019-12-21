import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Shapes 1.12
import QtQuick.Layouts 1.12

import Zorgi 1.0
import Model 1.0
import Controls 1.0



Window
{
    id : root

    visible: true

    width: 640
    height: 480
    minimumWidth: 640
    minimumHeight: 480

    title: qsTr("Zorgi")
    color: styler.backgroundColor

    MainMenu
    {
        id: menu
        visible: true
        focus: true
        opacity: 100

        anchors.fill: parent
        anchors.centerIn: parent
        onStartRequested: function()
        {
            menu.visible = false;
            gameView.visible = true;
        }

        onSettingsRequested: function()
        {
            menu.visible = false;
            settingsMenu.visible = true;
        }
    }

    GameView
    {
        id: gameView
        visible: false
        focus: false

        anchors.fill: parent
        anchors.centerIn: parent
    }

    SettingsMenu
    {
        id: settingsMenu
        visible: false
        focus: false

        anchors.fill: parent
        anchors.centerIn: parent

        onSetRequested: function()
        {
            menu.visible = true;
            settingsMenu.visible = false;
        }

        onBackRequested: function()
        {
            menu.visible = true;
            settingsMenu.visible = false;
        }
    }

    Component.onCompleted:
    {
        root.showFullScreen();
    }

    Styler
    {
        id: styler
    }

    Game
    {
        id : game
    }

    KeyEmitter
    {
        id : keyEmitter
    }
}
