#ifndef WEATHERFORMATTER_H
#define WEATHERFORMATTER_H

#include <QString>

#include "../types/WeatherUnits.h"

class WeatherFormatter final
{

public:
    static QString temperature(double value, TemperatureUnit unit);
    static QString dewPoint(double value, TemperatureUnit unit);
    static QString windSpeed(double value, WindSpeedUnit unit);
    static QString precipitation(double value, PrecipitationUnit unit);
    static QString pressure(double value);
};

#endif // WEATHERFORMATTER_H
