#ifndef WEATHERPARSER_H
#define WEATHERPARSER_H

#include "../common/types/WeatherDataTypes.h"

#include <QJsonObject>

class WeatherParser final {

public:
    static WeatherHeroData parseHero(const QJsonObject &json);
    static WeatherMetricsData parseMetrics(const QJsonObject &json);
    static WeatherAstronomyData parseAstronomy(const QJsonObject &json);
    static WeatherTimelineData parseTimeline(const QJsonObject &json);
};

#endif // WEATHERPARSER_H
