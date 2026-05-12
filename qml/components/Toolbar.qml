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

        Searchbar {
            id: searchbar
            Layout.preferredWidth: root.width * 0.7
            Layout.preferredHeight: root.height
            Layout.leftMargin: root.width * 0.1
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
