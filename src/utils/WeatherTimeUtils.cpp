#include "WeatherTimeUtils.h"

#include <QStringList>
#include <QDebug>

bool WeatherTimeUtils::isDay(
    const QString &currentTime,
    const QString &sunrise,
    const QString &sunset
) {
    const int currentMinutes = toMinutes(currentTime);
    const int sunriseMinutes = toMinutes(sunrise);
    const int sunsetMinutes = toMinutes(sunset);

    return currentMinutes >= sunriseMinutes && currentMinutes < sunsetMinutes;
}

int WeatherTimeUtils::toMinutes(const QString &time) {
    const QStringList parts = time.split(':');

    const int hours = parts[0].toInt();
    const int minutes = parts[1].toInt();

    return toMinutes(hours, minutes);
}

int WeatherTimeUtils::toMinutes(int hours, int minutes) {
    return hours * 60 + minutes;
}
