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
            Layout.leftMargin: 4
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
            spacing: label.Layout.leftMargin
            orientation: ListView.Horizontal
            clip: true

            model: weatherModel.timeline.hourlyForecastModel

            delegate: Item {
                width: hourlyView.height * 0.5
                height: hourlyView.height

                HourlyForecastItem {
                    anchors.fill: parent
                    hour: modelData.time
                    temperature: modelData.temperature
                    humidity: modelData.humidity
                    icon: modelData.icon
                }
            }
        }
    }
}
