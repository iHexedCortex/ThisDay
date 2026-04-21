import QtQuick 2.15
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: Theme.primaryColor
    border.color: Qt.darker(Theme.primaryColor, 1.3)
    border.width: 1
    radius: height * 0.5

    enum ThemeMode { Dark, Light }
    property int currentThemeMode: ThemeSwitch.ThemeMode.Dark

    function switchTheme() {
        switch(currentThemeMode) {
            case ThemeSwitch.ThemeMode.Dark: {
                currentThemeMode = ThemeSwitch.ThemeMode.Light;
                Theme.isDark = false;
                break;
            }
            case ThemeSwitch.ThemeMode.Light: {
                currentThemeMode = ThemeSwitch.ThemeMode.Dark;
                Theme.isDark = true;
                break;
            }
        }
    }

    Image {
        id: iconImage
        anchors.centerIn: parent
        source: Directory.themeIcons + getThemeName(parent.currentThemeMode) + "-theme.svg"
        width: parent.width * 0.6
        height: width
        fillMode: Image.PreserveAspectFit

        function getThemeName(themeMode) {
            switch(themeMode) {
                case ThemeSwitch.ThemeMode.Dark: return "dark";
                case ThemeSwitch.ThemeMode.Light: return "light";
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: parent.switchTheme()
    }
}
