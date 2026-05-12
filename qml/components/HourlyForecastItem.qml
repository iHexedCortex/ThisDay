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

    required property string hour
    required property string temperature
    required property string humidity
    required property string icon

    function humidityLevel(humidity) {
        if (humidity < 35) return "low";
        if (humidity < 75) return "medium";
        return "high";
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.topMargin: root.height * 0.03
        anchors.bottomMargin: anchors.topMargin
        spacing: 0

        Text {
            id: hourText
            text: root.hour
            color: "white"
            font.pixelSize: root.height * 0.1
            font.bold: true
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }

        Image {
            id: weatherIconImage
            source: Directory.weatherIcons + root.icon + ".png"
            Layout.preferredWidth: root.height * 0.32
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignHCenter
            verticalAlignment: Image.AlignVCenter
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: temperatureText
            text: root.temperature
            color: "white"
            font.pixelSize: hourText.font.pixelSize * 2.2
            font.bold: true
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }

        RowLayout {
            id: humidityLayout
            Layout.alignment: Qt.AlignHCenter

            Image {
                id: humidityIconImage
                source: Directory.icons + "humidity-" + root.humidityLevel(root.humidity) + ".svg"
                Layout.preferredWidth: root.height * 0.1
                Layout.preferredHeight: Layout.preferredWidth
                Layout.alignment: Qt.AlignHCenter
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: humidityText
                text: root.humidity
                color: "white"
                font.pixelSize: hourText.font.pixelSize * 1.1
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }
        }
    }
}
