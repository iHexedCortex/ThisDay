#ifndef WEATHERTYPES_H
#define WEATHERTYPES_H

#include <QObject>

namespace WeatherTypes {
    Q_NAMESPACE

    enum class TemperatureUnit {
        Celsius,
        Fahrenheit
    };
    Q_ENUM_NS(TemperatureUnit)

    enum class RefreshRate {
        min15,
        min30,
        min60
    };
    Q_ENUM_NS(RefreshRate)
};

#endif // WEATHERTYPES_H
