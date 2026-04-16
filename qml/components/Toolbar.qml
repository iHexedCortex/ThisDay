import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    RowLayout {
        id: mainLayout
        anchors.fill: parent

        Item {
            id: sidebarToggleRectangle
            Layout.preferredWidth: searchbar.height * 0.7
            Layout.preferredHeight: Layout.preferredWidth

            Image {
                id: sidebarToggleImage
                anchors.fill: parent
                source: Directory.toolbarIcons + (window.sidebarExpanded ? "collapse.png" : "expand.png")
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: window.sidebarExpanded = !window.sidebarExpanded
            }
        }

        Searchbar {
            id: searchbar
            Layout.preferredWidth: window.width * 0.35
            Layout.preferredHeight: width * 0.075
            Layout.leftMargin: window.width * 0.1
        }

        Item {
            Layout.fillWidth: true
        }

        ThemeSwitch {
            id: themeSwitch
            Layout.preferredWidth: searchbar.height
            Layout.preferredHeight: Layout.preferredWidth
        }
    }
}
