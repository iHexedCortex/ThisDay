import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    radius: iconOnly ? height * 0.5 : height * 0.35
    border.width: isActive ? 1 : 0
    border.color: Theme.primaryColor
    color: isActive ? Theme.primaryColor : "transparent"

    required property string icon
    required property string label
    property int badgeCount: 0
    property bool isActive: false
    property bool iconOnly: false

    signal clicked()

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.leftMargin: root.width * 0.07
        anchors.rightMargin: anchors.leftMargin
        spacing: root.iconOnly ? 0 : root.width * 0.05

        Image {
            id: iconImage
            source: root.icon
            Layout.preferredWidth: root.iconOnly ? root.width * 0.7 : root.width * 0.12
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignHCenter
            fillMode: Image.PreserveAspectFit
            horizontalAlignment: Image.AlignHCenter
            verticalAlignment: Image.AlignVCenter
        }

        Text {
            id: labelText
            Layout.alignment: Qt.AlignVCenter
            text: root.label
            color: Theme.textColor
            font.pixelSize: root.height * 0.4
            font.weight: root.isActive ? Font.Bold : Font.DemiBold
            visible: !root.iconOnly
        }

        Item {
            Layout.fillWidth: !root.iconOnly
        }

        Rectangle {
            id: badgeCountRectangle
            Layout.preferredWidth: root.height * 0.55
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignVCenter
            radius: height * 0.5
            color: Theme.badgeColor
            visible: root.badgeCount && !root.iconOnly

            Text {
                id: badgeCountText
                anchors.centerIn: parent
                text: root.badgeCount
                color: Theme.textColor
                font.pixelSize: parent.height * 0.6
                font.bold: true
                visible: !root.iconOnly
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            root.clicked()
        }
    }
}
