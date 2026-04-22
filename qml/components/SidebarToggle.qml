import QtQuick 2.15
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: Theme.primaryColor
    border.color: Qt.darker(Theme.primaryColor, 1.3)
    border.width: 1
    radius: height * 0.5

    Image {
        id: iconImage
        anchors.centerIn: parent
        source: Directory.toolbarIcons + (window.sidebarExpanded ? "collapse.svg" : "expand.svg")
        width: parent.width * 0.6
        height: width
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: window.sidebarExpanded = !window.sidebarExpanded
    }
}
