import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../shared"

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
            Layout.leftMargin: 4
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
            spacing: label.Layout.leftMargin
            orientation: ListView.Horizontal
            clip: true

            model: weatherModel.timeline.dailyForecastModel

            delegate: Item {
                width: dailyForecastListView.height * 0.75
                height: dailyForecastListView.height

                DailyForecastItem {
                    anchors.fill: parent
                    week: modelData.week
                    condition: modelData.condition
                    maxTemperature: modelData.maxTemperature
                    minTemperature: modelData.minTemperature
                    icon: modelData.icon
                }
            }
        }
    }
}
