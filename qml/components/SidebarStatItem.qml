import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    required property string icon
    required property string label
    required property string value
    property bool iconOnly: false
    property bool rotatableImage: false

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.leftMargin: parent.width * 0.04
        anchors.rightMargin: anchors.leftMargin
        spacing: parent.width * 0.08

        Image {
            id: iconImage
            source: root.icon
            Layout.preferredWidth: root.height * 0.65
            Layout.preferredHeight: Layout.preferredWidth
            fillMode: Image.PreserveAspectFit

            RotationAnimation on rotation {
                running: WeatherData.loading && root.rotatableImage
                from: 0
                to: 360
                duration: 1000
                loops: Animation.Infinite

                onStopped: iconImage.rotation = 0
            }
        }

        ColumnLayout {
            id: labelAndValueLayout

            Text {
                id: labelText
                text: root.label
                Layout.fillWidth: true
                font.bold: true
                font.pixelSize: root.height * 0.22
                color: Theme.subTextColor
            }

            Shimmer {
                id: valueTextShimmer
                Layout.preferredWidth: root.width * 0.7
                Layout.preferredHeight: root.height * 0.45

                Text {
                    id: valueText
                    text: root.value
                    Layout.fillWidth: true
                    font.pixelSize: parent.height * 0.7
                    font.bold: true
                    color: Theme.textColor
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    visible: !valueTextShimmer.loading
                }
            }

        }
    }
}
