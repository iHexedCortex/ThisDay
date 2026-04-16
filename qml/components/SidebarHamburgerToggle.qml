import QtQuick 2.15

Rectangle {
    id: root
    color: "transparent"

    signal toggled()

    Image {
        id: iconImage
        anchors.fill: parent
        // source: ""
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            parent.toggled()
        }
    }
}
