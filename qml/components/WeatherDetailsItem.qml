import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    required property string label
    required property var value
    required property string icon
    property string extra

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
                    id: extraRectangle
                    Layout.preferredWidth: extraText.implicitWidth + root.width * 0.07
                    Layout.preferredHeight: extraText.implicitHeight
                    color: Theme.accentColor
                    radius: Layout.preferredHeight * 0.5
                    visible: !!extra

                    Text {
                        id: extraText
                        anchors.fill: parent
                        text: root.extra
                        color: Theme.textColor
                        font.pixelSize: root.height * 0.25
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

                Item {
                    Layout.fillWidth: true
                }
            }

            Text {
                id: valueText
                text: root.value
                color: Theme.textColor
                font.pixelSize: labelText.font.pixelSize * 1.2
                font.bold: true
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
