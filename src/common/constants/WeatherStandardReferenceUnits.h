#ifndef WEATHERSTANDARDREFERENCEUNITS_H
#define WEATHERSTANDARDREFERENCEUNITS_H

#include "../types/WeatherUnits.h"

namespace WeatherStandardReferenceUnits {
    inline constexpr TemperatureUnit Temperature = TemperatureUnit::Celsius;
    inline constexpr WindSpeedUnit WindSpeed = WindSpeedUnit::MS;
    inline constexpr PrecipitationUnit Precipitation = PrecipitationUnit::MM;
}

#endif // WEATHERSTANDARDREFERENCEUNITS_H
