#include "WeatherSummaryBuilder.h"

QString WeatherSummaryBuilder::build(const WeatherSummaryData &data) {
    const QString comfort = determineComfort(data.temperature, data.humidity);
    const QString activity = determineActivity(data);
    const QString view = determineView(data.visibility, data.cloudiness, data.condition);
    const QString airQuality = determineAirQuality(data.visibility, data.windSpeed, data.temperature);

    return QString("Comfort: %1     •     Activity: %2     •     View: %3     •     AQ: %4").arg(comfort, activity, view, airQuality);
}

QString WeatherSummaryBuilder::determineComfort(double temperature, double humidity) {
    if (temperature > 30 && humidity > 70) return "Extremely Sweltering";
    if (temperature > 25 && humidity > 65) return "Sticky & Humid";
    if (temperature >= 15 && temperature <= 24) return "Pleasant";
    if (temperature >= 5 && temperature < 15) return "Cool";
    if (temperature < 5 && temperature >= -10) return "Bone-Chilling";
    if (temperature < -10) return "Freezing Danger";

    return "Varies";
}

QString WeatherSummaryBuilder::determineActivity(const WeatherSummaryData &data) {
    if (data.temperature < -5) return "Dangerously Cold";
    if (data.temperature > 38) return "Extreme Heat Warning";
    if (data.uvIndex >= 8 && data.cloudiness < 20) return "High Burn Risk";
    if (data.condition == "Rain" || data.windSpeed > 15) return "Poor Conditions";
    if (data.temperature >= 10 && data.temperature <= 28) return "Ideal for Outdoors";

    return "Stay Alert";
}

QString WeatherSummaryBuilder::determineView(double visibility, double cloudiness, const QString &condition) {
    if (visibility < 1) return "Dense Fog";
    if (visibility < 5) return "Hazy / Low Visibility";
    if (condition == "Snow") return "Snow Blurriness";
    if (cloudiness < 10 && visibility >= 10) return "Crystal Clear";
    if (cloudiness > 90) return "Overcast Skies";

    return "Typical Clarity";
}

QString WeatherSummaryBuilder::determineAirQuality(double visibility, double windSpeed, double temperature) {
    if (visibility > 15 && windSpeed < 5) return "Crisp Air";
    if (visibility < 8) return "Dusty / Hazy";
    if (temperature < 0) return "Sharp / Frosty";

    return "Fresh Breeze";
}
