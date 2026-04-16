import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    required property string label
    required property var value
    required property string unit
    required property string icon
    property string direction
    property string level

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: root.width * 0.05

        Image {
            id: iconImage
            source: icon
            Layout.preferredWidth: root.height * 0.8
            Layout.preferredHeight: Layout.preferredWidth
            fillMode: Image.PreserveAspectFit
        }

        ColumnLayout {
            id: informationLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            RowLayout {
                id: labelLayout
                Layout.fillWidth: true

                Text {
                    id: labelText
                    text: root.label
                    color: Theme.subTextColor
                    font.pixelSize: root.height * 0.3
                    font.weight: Font.DemiBold
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }

                Item {
                    Layout.fillWidth: true
                }

                Rectangle {
                    id: levelRectangle
                    Layout.preferredWidth: root.width * 0.1
                    Layout.preferredHeight: Layout.preferredWidth
                    color: Theme.accentColor
                    radius: Layout.preferredHeight * 0.5
                    visible: !!level

                    Text {
                        id: levelText
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: root.level
                        color: Theme.textColor
                        font.pixelSize: parent.height * 0.7
                        font.weight: Font.DemiBold
                    }
                }
            }

            RowLayout {
                id: valueLayout
                Layout.fillWidth: true

                Text {
                    id: valueText
                    text: root.value + root.unit
                    color: Theme.textColor
                    font.pixelSize: labelText.font.pixelSize * 1.2
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }

                Item {
                    Layout.fillWidth: true
                }

                Rectangle {
                    id: directionRectangle
                    Layout.preferredWidth: root.width * 0.2
                    Layout.preferredHeight: Layout.preferredWidth * 0.6
                    color: Theme.primaryColor
                    radius: Layout.preferredHeight * 0.4
                    visible: !!root.direction

                    Text {
                        id: directionText
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: root.direction
                        color: Theme.textColor
                        font.pixelSize: parent.height * 0.7
                        font.weight: Font.DemiBold
                    }
                }
            }
        }
    }
}
