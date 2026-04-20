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

        SidebarToggle {
            id: sidebarToggle
            Layout.preferredWidth: searchbar.height
            Layout.preferredHeight: Layout.preferredWidth
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
            Layout.preferredWidth: sidebarToggle.height
            Layout.preferredHeight: Layout.preferredWidth
        }
    }
}
