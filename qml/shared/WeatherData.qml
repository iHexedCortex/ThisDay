pragma Singleton
import QtQuick 2.15

QtObject {
    property int temperature: weatherProvider.temperature
    property int maxTemperature: weatherProvider.maxTemperature
    property int minTemperature: weatherProvider.minTemperature
    property int feelsLike: weatherProvider.feelsLike
    property int humidity: weatherProvider.humidity
    property real windSpeed: weatherProvider.windSpeed
    property int pressure: weatherProvider.pressure
    property int cloudiness: weatherProvider.cloudiness
    property real visibility: weatherProvider.visibility
    property real dewPoint: weatherProvider.dewPoint
    property real precipitation: weatherProvider.precipitation
    property string uvLevel: weatherProvider.uvLevel
    property int uvIndex: weatherProvider.uvIndex
    property string condition: weatherProvider.condition
    property string sunrise: weatherProvider.sunrise
    property string sunset: weatherProvider.sunset
    property string city: weatherProvider.city
    property var hourlyForecastModel: weatherProvider.hourlyForecastModel
    property var dailyForecastModel: weatherProvider.dailyForecastModel
    property string lastUpdatedTime: weatherProvider.lastFetchedTime
    property bool loading: weatherProvider.isLoading

    property string clothingAdvice: {
        if (temperature < 10) return "Heavy Coat"
        if (temperature < 20) return "Light Jacket"
        return "T-Shirt weather!"
    }

    property string outdoorVibe: {
        if (condition === "Rain") return "Grab an umbrella"
        if (humidity > 80) return "Sticky & Humid"
        return "Great for a walk"
    }

    property bool isGoodForFootball: (temperature > 10 && temperature < 25 && condition !== "Rain")
}
