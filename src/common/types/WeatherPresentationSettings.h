#ifndef WEATHERPRESENTATIONSETTINGS_H
#define WEATHERPRESENTATIONSETTINGS_H

#include "./WeatherUnits.h"

struct WeatherPresentationSettings final {
    TemperatureUnit temperatureUnit;
    WindSpeedUnit windSpeedUnit;
    PrecipitationUnit precipitationUnit;
};

#endif // WEATHERPRESENTATIONSETTINGS_H
