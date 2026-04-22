import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../shared"

Rectangle {
    id: root
    color: Theme.surfaceColor
    border.color: Theme.cardBorderColor
    border.width: 1

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: 2
        spacing: 0

        Text {
            id: label
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.2
            Layout.leftMargin: window.width * 0.01
            text: "Hourly Forecast"
            color: Theme.textColor
            font.pixelSize: height * 0.7
            font.bold: true
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        ListView {
            id: hourlyView
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.7
            spacing: window.width * 0.004
            orientation: ListView.Horizontal
            clip: true

            model: WeatherData.hourlyForecastModel

            delegate: Item {
                width: window.width * 0.052
                height: hourlyView.height

                HourlyForecastItem {
                    anchors.fill: parent
                    hour: modelData.time
                    temperature: modelData.temperature
                    condition: modelData.condition
                    humidity: modelData.humidity
                    icon: Directory.weatherIcons + modelData.condition + ".png";
                }
            }
        }
    }
}
