#include "WeatherEnumMapper.h"

QString WeatherEnumMapper::temperature(TemperatureUnit unit) {
    Q_UNUSED(unit)

    return "°";
}

QString WeatherEnumMapper::windSpeed(WindSpeedUnit unit) {
    switch(unit) {
        case WindSpeedUnit::KMH: return "km/h";
        case WindSpeedUnit::MPH: return "mph";
        case WindSpeedUnit::MS: return "m/s";
        default: return "";
    }
}

QString WeatherEnumMapper::precipitation(PrecipitationUnit unit) {
    switch(unit) {
        case PrecipitationUnit::IN: return "in";
        case PrecipitationUnit::MM: return "mm";
        default: return "";
    }
}
