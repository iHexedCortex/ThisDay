import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"
import "../shared/utils/DataConverter.js" as DataConverter
import "../shared/utils/DataPrettier.js" as DataPrettier
import Weather.Types 1.0

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
            value: WeatherData.windSpeed
            unit: "m/s"
            extra: WeatherData.windDirection
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

        Item {
            Layout.fillWidth: true
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

        Item {
            Layout.fillWidth: true
        }

        WeatherDetailsItem {
            id: uvLevelItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "uv.png"
            label: "UV Level"
            value: WeatherData.uvLevel
            level: WeatherData.uvIndex
        }

        WeatherDetailsItem {
            id: dewPointItem
            Layout.preferredWidth: windItem.width
            Layout.preferredHeight: windItem.height
            icon:  Directory.weatherDetailsIcons + "dew.png"
            label: "Dew Point"
            value: DataPrettier.dewPoint((DataConverter.temperature(WeatherData.dewPoint, settings.temperatureUnit)))
            unit: "°"
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
            value: WeatherData.cloudiness
            unit: "%"
        }
    }
}
