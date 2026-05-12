#include "WeatherDomainFormatter.h"

QString WeatherDomainFormatter::pressure(double value) {
    return QString("%1 hPa").arg(value);
}

QString WeatherDomainFormatter::visibility(double value) {
    return QString("%1 m").arg(value);
}

QString WeatherDomainFormatter::percent(double value) {
    return QString("%1%").arg(value);
}
