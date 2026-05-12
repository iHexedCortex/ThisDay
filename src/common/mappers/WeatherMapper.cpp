#include "WeatherMapper.h"

#include <QTime>
#include <QDateTime>

#include "./WeatherSemanticMapper.h"
#include "../formatters/WeatherFormatter.h"
#include "../formatters/WeatherDomainFormatter.h"
#include "../../utils/WeatherTimeUtils.h"

WeatherHeroModel WeatherMapper::mapHero(
    const WeatherHeroData &heroData,
    const WeatherAstronomyData &astronomyData,
    const WeatherPresentationSettings &settings
) {
    WeatherHeroModel heroModel;

    const QString condition = WeatherSemanticMapper::condition(heroData.conditionCode);
    const bool isDay = WeatherTimeUtils::isDay(
        QTime::currentTime().toString("HH:mm"),
        QDateTime::fromString(astronomyData.sunrise, Qt::ISODate).time().toString("HH:mm"),
        QDateTime::fromString(astronomyData.sunset, Qt::ISODate).time().toString("HH:mm")
    );

    heroModel.temperature = WeatherFormatter::temperature(heroData.temperature, settings.temperatureUnit);
    heroModel.condition = condition;
    heroModel.maxTemperature = WeatherFormatter::temperature(heroData.maxTemperature, settings.temperatureUnit);
    heroModel.minTemperature = WeatherFormatter::temperature(heroData.minTemperature, settings.temperatureUnit);
    heroModel.feelsLikeTemperature = WeatherFormatter::temperature(heroData.feelsLikeTemperature, settings.temperatureUnit);
    heroModel.icon = WeatherSemanticMapper::icon(condition, isDay);

    return heroModel;
}

WeatherMetricsModel WeatherMapper::mapMetrics(
    const WeatherMetricsData &metricsData,
    const WeatherPresentationSettings &settings
) {
    WeatherMetricsModel metricsModel;

    metricsModel.windSpeed = WeatherFormatter::windSpeed(metricsData.windSpeed, settings.windSpeedUnit);
    metricsModel.windDirection = WeatherSemanticMapper::windDirection(metricsData.windDirectionDeg);
    metricsModel.humidity = WeatherDomainFormatter::percent(metricsData.humidity);
    metricsModel.pressure = WeatherDomainFormatter::pressure(metricsData.pressure);
    metricsModel.dewPoint = WeatherFormatter::dewPoint(metricsData.dewPoint, settings.temperatureUnit);
    metricsModel.precipitation = WeatherFormatter::precipitation(metricsData.precipitation, settings.precipitationUnit);
    metricsModel.visibility = WeatherDomainFormatter::visibility(metricsData.visibility);
    metricsModel.uvIndex = metricsData.uvIndex;
    metricsModel.uvLevel = WeatherSemanticMapper::uvLevel(metricsData.uvIndex);
    metricsModel.cloudiness = WeatherDomainFormatter::percent(metricsData.cloudiness);

    return metricsModel;
}

WeatherAstronomyModel WeatherMapper::mapAstronomy(
    const WeatherAstronomyData &astronomyData,
    const WeatherPresentationSettings &settings
) {
    WeatherAstronomyModel astronomyModel;

    astronomyModel.sunrise = QDateTime::fromString(astronomyData.sunrise, Qt::ISODate).time().toString("HH:mm");
    astronomyModel.sunset = QDateTime::fromString(astronomyData.sunset, Qt::ISODate).time().toString("HH:mm");

    return astronomyModel;
}

WeatherTimelineModel WeatherMapper::mapTimeline(
    const WeatherTimelineData &timelineData,
    const WeatherAstronomyData &astronomyData,
    const WeatherPresentationSettings &settings
) {
    WeatherTimelineModel timelineModel;

    auto hourlyForecastData = timelineData.hourlyForecast;
    auto dailyForecastData = timelineData.dailyForecast;

    for (WeatherHourlyForecastUnitData &hourlyForecastUnitData : hourlyForecastData) {
        WeatherHourlyForecastUnitModel hourlyForecastUnitModel;

        const QString time = QDateTime::fromString(hourlyForecastUnitData.dateTime, Qt::ISODate).time().toString("HH:mm");
        const QString condition = WeatherSemanticMapper::condition(hourlyForecastUnitData.conditionCode);
        const bool isDay = WeatherTimeUtils::isDay(
            time,
            QDateTime::fromString(astronomyData.sunrise, Qt::ISODate).time().toString("HH:mm"),
            QDateTime::fromString(astronomyData.sunset, Qt::ISODate).time().toString("HH:mm")
        );

        hourlyForecastUnitModel.time = time;
        hourlyForecastUnitModel.icon = WeatherSemanticMapper::icon(condition, isDay);
        hourlyForecastUnitModel.temperature = WeatherFormatter::temperature(hourlyForecastUnitData.temperature, settings.temperatureUnit);
        hourlyForecastUnitModel.humidity = WeatherDomainFormatter::percent(hourlyForecastUnitData.humidity);

        timelineModel.hourlyForecastModel.append(hourlyForecastUnitModel);
    }

    bool isTomorrow = false;
    bool isToday = !isTomorrow;
    for (WeatherDailyForecastUnitData &dailyForecastUnitData : dailyForecastData) {
        if (isToday) {
            isTomorrow = true;
            isToday = !isTomorrow;
            continue;
        }

        WeatherDailyForecastUnitModel dailyForecastUnitModel;

        const QString week = QDateTime::fromString(dailyForecastUnitData.dateTime, Qt::ISODate).date().toString("dddd");
        const QString condition = WeatherSemanticMapper::condition(dailyForecastUnitData.conditionCode);

        if (isTomorrow) {
            dailyForecastUnitModel.week = "Tomorrow";
            isTomorrow = false;
        } else
            dailyForecastUnitModel.week = week;

        dailyForecastUnitModel.icon = WeatherSemanticMapper::icon(condition, true);
        dailyForecastUnitModel.maxTemperature = WeatherFormatter::temperature(dailyForecastUnitData.maxTemperature, settings.temperatureUnit);
        dailyForecastUnitModel.minTemperature = WeatherFormatter::temperature(dailyForecastUnitData.minTemperature, settings.temperatureUnit);
        dailyForecastUnitModel.condition = condition;

        timelineModel.dailyForecastModel.append(dailyForecastUnitModel);
    }

    return timelineModel;
}
