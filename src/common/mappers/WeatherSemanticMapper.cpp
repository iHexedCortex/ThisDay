#include "WeatherSemanticMapper.h"

#include <QStringList>

QString WeatherSemanticMapper::condition(int code)
{
    switch (code) {
        case 0:
            return "Clear sky";

        case 1:
        case 2:
            return "Partly cloudy";

        case 3:
            return "Cloudy";

        case 45:
        case 48:
            return "Fog";

        case 51:
        case 53:
        case 55:
        case 56:
        case 57:
            return "Drizzle";

        case 61:
        case 63:
        case 65:
        case 66:
        case 67:
        case 80:
        case 81:
        case 82:
            return "Rain";

        case 71:
        case 73:
        case 75:
        case 77:
        case 85:
        case 86:
            return "Snow";

        case 95:
        case 96:
        case 99:
            return "Thunderstorm";

        default:
            return "unknown";
    }
}

QString WeatherSemanticMapper::uvLevel(int uvIndex) {
    if (uvIndex < 3) return "Low";
    else if (uvIndex < 6) return "Moderate";
    else if (uvIndex < 8) return "High";
    else if (uvIndex < 11) return "Very High";
    return "Extreme";
}

QString WeatherSemanticMapper::icon(const QString &condition, bool isDay) {
    const QString normalized = condition.toLower().replace(' ', '_');
    const QString suffix = isDay ? "_day" : "_night";

    return normalized + suffix;
}

QString WeatherSemanticMapper::windDirection(double degrees)
{
    static const QStringList directions = {
        "N", "NNE", "NE", "ENE",
        "E", "ESE", "SE", "SSE",
        "S", "SSW", "SW", "WSW",
        "W", "WNW", "NW", "NNW"
    };

    const int index = qRound(degrees / 22.5) % directions.size();

    return directions[index];
}
