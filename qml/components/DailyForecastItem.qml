import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../shared"

Rectangle {
    id: root
    border.width: 1
    border.color: Theme.primaryColor
    radius: height * 0.1

    gradient: Gradient {
        GradientStop { position: 0.0; color: Theme.primaryColor }
        GradientStop { position: 1.0; color: Qt.darker(Theme.primaryColor, 2) }
    }

    required property string week
    required property string condition
    required property color bubbleColor
    required property int maxTemperature
    required property int minTemperature

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.topMargin: root.height * 0.03
        anchors.bottomMargin: anchors.topMargin
        spacing: 0

        Text {
            id: weekText
            Layout.alignment: Qt.AlignHCenter
            text: root.week
            color: "white"
            font.pixelSize: root.height * 0.11
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Image {
            id: iconImage
            source: Directory.weatherIcons + root.condition + ".png"
            Layout.preferredWidth: root.height * 0.4
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignHCenter
            fillMode: Image.PreserveAspectFit
        }

        RowLayout {
            id: temperatureRangeLayout
            Layout.fillWidth: true
            Layout.fillHeight: true

            Item {
                Layout.fillWidth: true
            }

            Text {
                id: maxTemperatureText
                Layout.alignment: Qt.AlignHCenter
                text: root.maxTemperature + "°"
                color: "white"
                font.pixelSize: weekText.font.pixelSize * 1.8
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: minTemperatureText
                Layout.alignment: Qt.AlignHCenter
                text: root.minTemperature + "°"
                color: "lightgray"
                font.pixelSize: weekText.font.pixelSize * 1.4
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Item {
                Layout.fillWidth: true
            }
        }

        Rectangle {
            id: conditionRectangle
            Layout.preferredWidth: root.condition.length * root.width * 0.08
            Layout.preferredHeight: root.width * 0.17
            Layout.alignment: Qt.AlignHCenter
            radius: height * 0.5
            color: "transparent"

            Text {
                id: conditionText
                anchors.fill: parent
                text: root.condition
                color: "white"
                font.pixelSize: parent.height * 0.8
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
