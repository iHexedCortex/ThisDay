#ifndef DEFAULTSETTINGS_H
#define DEFAULTSETTINGS_H

#include "../common/types/WeatherUnits.h"

namespace DefaultSettings {
    inline constexpr TemperatureUnit TEMPERATURE_UNIT = TemperatureUnit::Celsius;
    inline constexpr WindSpeedUnit WIND_SPEED_UNIT = WindSpeedUnit::MS;
    inline constexpr PrecipitationUnit PRECIPITATION_UNIT = PrecipitationUnit::MM;
}

#endif // DEFAULTSETTINGS_H
