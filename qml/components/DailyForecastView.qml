import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../shared"
import "../shared/utils/DataConverter.js" as DataConverter
import "../shared/utils/DataPrettier.js" as DataPrettier

Rectangle {
    id: root
    color: Theme.surfaceColor
    border.width: 1
    border.color: Theme.cardBorderColor

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
            text: "Daily Forecast"
            color: Theme.textColor
            font.pixelSize: height * 0.7
            font.bold: true
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        ListView {
            id: dailyForecastListView
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.7
            spacing: window.width * 0.004
            orientation: ListView.Horizontal
            clip: true

            model: WeatherData.dailyForecastModel

            delegate: Item {
                width: window.width * 0.07
                height: dailyForecastListView.height

                DailyForecastItem {
                    anchors.fill: parent
                    week: modelData.week
                    condition: modelData.condition
                    maxTemperature:  DataPrettier.temperature((DataConverter.temperature(modelData.maxTemperature, settings.temperatureUnit)))
                    minTemperature: DataPrettier.temperature((DataConverter.temperature(modelData.minTemperature, settings.temperatureUnit)))
                }
            }
        }
    }
}
