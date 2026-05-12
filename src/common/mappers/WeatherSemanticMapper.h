#ifndef WEATHERSEMANTICMAPPER_H
#define WEATHERSEMANTICMAPPER_H

#include <QString>

class WeatherSemanticMapper final
{

public:
    static QString uvLevel(int uvIndex);
    static QString condition(int code);
    static QString icon(const QString &condition, bool isDay);
    static QString windDirection(double degrees);
};

#endif // WEATHERSEMANTICMAPPER_H
