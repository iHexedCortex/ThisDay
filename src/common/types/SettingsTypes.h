#ifndef SETTINGSTYPES_H
#define SETTINGSTYPES_H

#include "WeatherUnits.h"

struct UnitSettings {
    TemperatureUnit temperature;
    WindSpeedUnit windSpeed;
    PrecipitationUnit precipitation;
};

#endif // SETTINGSTYPES_H
