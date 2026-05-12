#ifndef WEATHERMAPPER_H
#define WEATHERMAPPER_H

#include <QString>

#include "../types/WeatherUnits.h"
#include "../types/WeatherModelTypes.h"
#include "../types/WeatherDataTypes.h"
#include "../types/WeatherPresentationSettings.h"

class WeatherMapper final {

public:
    static WeatherHeroModel mapHero(
        const WeatherHeroData &heroData,
        const WeatherAstronomyData &astronomyData,
        const WeatherPresentationSettings &settings
    );

    static WeatherMetricsModel mapMetrics(
        const WeatherMetricsData &metricsData,
        const WeatherPresentationSettings &settings
    );

    static WeatherAstronomyModel mapAstronomy(
        const WeatherAstronomyData &astronomyData,
        const WeatherPresentationSettings &settings
    );

    static WeatherTimelineModel mapTimeline(
        const WeatherTimelineData &timelineData,
        const WeatherAstronomyData &astronomyData,
        const WeatherPresentationSettings &settings
    );
};

#endif // WEATHERMAPPER_H
