#ifndef DEFAULTSETTINGS_H
#define DEFAULTSETTINGS_H

#include "../common/types/WeatherTypes.h"

namespace DefaultSettings {
    inline constexpr WeatherTypes::TemperatureUnit TEMPERATURE_UNIT = WeatherTypes::TemperatureUnit::Celsius;
    inline constexpr WeatherTypes::RefreshRate REFRESH_RATE = WeatherTypes::RefreshRate::min60;
}

#endif // DEFAULTSETTINGS_H
