#ifndef WEATHERENUMMAPPER_H
#define WEATHERENUMMAPPER_H

#include <QString>

#include "../types/WeatherUnits.h"

class WeatherEnumMapper final
{

public:
    static QString temperature(TemperatureUnit unit);
    static QString windSpeed(WindSpeedUnit unit);
    static QString precipitation(PrecipitationUnit unit);
};

#endif // WEATHERENUMMAPPER_H
