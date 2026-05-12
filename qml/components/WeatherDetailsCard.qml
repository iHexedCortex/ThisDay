import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    GridLayout {
        id: mainLayout
        anchors.fill: parent
        columns: 3
        rowSpacing: 0
        columnSpacing: 0

        WeatherDetailsItem {
            id: windItem
            Layout.preferredWidth: root.width * 0.48
            Layout.preferredHeight: Layout.preferredWidth * 0.35
            icon:  Directory.weatherDetailsIcons + "wind.png"
            label: "Wind"
            value: weatherModel.metrics.windSpeed
            extra: weatherModel.metrics.windDirection
        }

        Item {
            Layout.fillWidth: true
        }

        WeatherDetailsItem {
            id: precipitationItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "precipitation.png"
            label: "Precipitation"
            value: weatherModel.metrics.precipitation
        }

        WeatherDetailsItem {
            id: humidityItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "humidity.png"
            label: "Humidity"
            value: weatherModel.metrics.humidity
        }

        Item {
            Layout.fillWidth: true
        }

        WeatherDetailsItem {
            id: visibilityItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "visibility.png"
            label: "Visibility"
            value: weatherModel.metrics.visibility
        }

        WeatherDetailsItem {
            id: pressureItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "pressure.png"
            label: "Pressure"
            value: weatherModel.metrics.pressure
        }

        Item {
            Layout.fillWidth: true
        }

        WeatherDetailsItem {
            id: uvLevelItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "uv.png"
            label: "UV Level"
            value: weatherModel.metrics.uvLevel
            extra: weatherModel.metrics.uvIndex
        }

        WeatherDetailsItem {
            id: dewPointItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "dew.png"
            label: "Dew Point"
            value: weatherModel.metrics.dewPoint
        }

        Item {
            Layout.fillWidth: true
        }

        WeatherDetailsItem {
            id: cloudinessItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "cloudiness.png"
            label: "Cloudiness"
            value: weatherModel.metrics.cloudiness
        }
    }
}
