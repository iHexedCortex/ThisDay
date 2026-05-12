#ifndef WEATHERSUMMARYBUILDER_H
#define WEATHERSUMMARYBUILDER_H

#include <QString>

#include "../types/WeatherDataTypes.h"

class WeatherSummaryBuilder final
{

public:
    static QString build(const WeatherSummaryData &data);

private:
    static QString determineComfort(double temperature, double humidity);
    static QString determineActivity(const WeatherSummaryData &data);
    static QString determineView(double visibility, double cloudiness, const QString &condition);
    static QString determineAirQuality(double visibility, double windSpeed, double temperature);
};

#endif // WEATHERSUMMARYBUILDER_H
