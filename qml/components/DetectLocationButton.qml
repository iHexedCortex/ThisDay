import QtQuick 2.15
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    signal clicked()

    Image {
        id: iconImage
        source: Directory.sidebarIcons + "location.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            parent.clicked()
        }
    }
}
