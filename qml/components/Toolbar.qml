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
            Layout.preferredWidth: window.width * 0.5
            Layout.preferredHeight: window.width * 0.03
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
