#include "WeatherFormatter.h"

#include "../../utils/WeatherCalculator.h"
#include "../mappers/WeatherEnumMapper.h"

QString WeatherFormatter::temperature(double value, TemperatureUnit unit) {
    const double converted = WeatherCalculator::temperature(value, unit);
    const double rounded = qRound(converted);
    const QString unitStr = WeatherEnumMapper::temperature(unit);

    return QString("%1%2")
        .arg(rounded)
        .arg(unitStr);
}

QString WeatherFormatter::dewPoint(double value, TemperatureUnit unit) {
    const double converted = WeatherCalculator::temperature(value, unit);
    const QString unitStr = WeatherEnumMapper::temperature(unit);

    return QString("%1%2")
        .arg(QString::number(converted, 'f', 1))
        .arg(unitStr);
}

QString WeatherFormatter::windSpeed(double value, WindSpeedUnit unit) {
    const double converted = WeatherCalculator::windSpeed(value, unit);
    const QString unitStr = WeatherEnumMapper::windSpeed(unit);

    return QString("%1 %2")
        .arg(converted)
        .arg(unitStr);
}

QString WeatherFormatter::precipitation(double value, PrecipitationUnit unit) {
    const double converted = WeatherCalculator::precipitation(value, unit);
    const QString unitStr = WeatherEnumMapper::precipitation(unit);

    return QString("%1 %2")
        .arg(converted)
        .arg(unitStr);
}
