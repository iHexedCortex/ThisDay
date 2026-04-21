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
        columns: 2
        rowSpacing: 0
        columnSpacing: 0

        WeatherDetailsItem {
            id: windItem
            Layout.preferredWidth: root.width * 0.4
            Layout.preferredHeight: Layout.preferredWidth * 0.35
            icon:  Directory.weatherDetailsIcons + "wind.png"
            label: "Wind"
            value: WeatherData.windSpeed
            unit: "km/h"
            extra: WeatherData.windDirection
        }

        WeatherDetailsItem {
            id: precipitationItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "precipitation.png"
            label: "Precipitation"
            value: WeatherData.precipitation
            unit: "mm"
        }

        WeatherDetailsItem {
            id: humidityItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "humidity.png"
            label: "Humidity"
            value: WeatherData.humidity
            unit: "%"
        }

        WeatherDetailsItem {
            id: visibilityItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "visibility.png"
            label: "Visibility"
            value: WeatherData.visibility
            unit: "km"
        }

        WeatherDetailsItem {
            id: pressureItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "pressure.png"
            label: "Pressure"
            value: WeatherData.pressure
            unit: "hPa"
        }

        WeatherDetailsItem {
            id: uvLevelItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "uv.png"
            label: "UV Level"
            value: WeatherData.uvLevel
            unit: ""
            level: WeatherData.uvIndex
        }

        WeatherDetailsItem {
            id: dewPointItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "dew.png"
            label: "Dew Point"
            value: WeatherData.dewPoint
            unit: "°C"
        }

        WeatherDetailsItem {
            id: cloudinessItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "cloudiness.png"
            label: "Cloudiness"
            value: WeatherData.cloudiness
            unit: "%"
        }
    }
}
