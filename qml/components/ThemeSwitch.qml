import QtQuick 2.15
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: Theme.primaryColor
    border.color: Qt.darker(Theme.primaryColor, 1.3)
    border.width: 1
    radius: height * 0.5

    property var themes: ["dark", "light", "auto"]
    property int currentThemeIndex: 0

    function switchTheme() {
        let nextThemeIndex = currentThemeIndex + 1;
        if (nextThemeIndex == themes.length)
            nextThemeIndex = 0;

        currentThemeIndex = nextThemeIndex;
        Theme.isDark = currentThemeIndex == 0;
    }

    Image {
        id: iconImage
        anchors.centerIn: parent
        source: "qrc:/qt/qml/ThisDay/resources/icons/theme/" + parent.themes[parent.currentThemeIndex] + "-theme.svg"
        width: parent.width * 0.6
        height: width
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: parent.switchTheme()
    }
}
