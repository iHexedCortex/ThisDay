#ifndef WEATHERTIMEUTILS_H
#define WEATHERTIMEUTILS_H

#include <QString>

class WeatherTimeUtils
{

public:
    static bool isDay(
        const QString &currentTime,
        const QString &sunrise,
        const QString &sunset
    );

private:
    static int toMinutes(const QString &time);
    static int toMinutes(int hours, int minutes);
};

#endif // WEATHERTIMEUTILS_H
