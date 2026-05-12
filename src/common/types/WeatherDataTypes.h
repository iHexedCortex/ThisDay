#ifndef WEATHERDATATYPES_H
#define WEATHERDATATYPES_H

#include <QString>
#include <QList>

struct WeatherDailyForecastUnitData {
    QString dateTime;
    double maxTemperature;
    double minTemperature;
    double conditionCode;
};

struct WeatherHourlyForecastUnitData {
    QString dateTime;
    double temperature;
    double conditionCode;
    int humidity;
};

struct WeatherHeroData final {
    double temperature;
    double maxTemperature;
    double minTemperature;
    double feelsLikeTemperature;
    int conditionCode;
};

struct WeatherMetricsData final {
    double windSpeed;
    double windDirectionDeg;
    int humidity;
    int pressure;
    double dewPoint;
    double visibility;
    double precipitation;
    int cloudiness;
    int uvIndex;
    QString uvLevel;
};

struct WeatherAstronomyData final {
    QString sunrise;
    QString sunset;
};

struct WeatherTimelineData final {
    QList<WeatherDailyForecastUnitData> dailyForecast;
    QList<WeatherHourlyForecastUnitData> hourlyForecast;
};

struct WeatherSummaryData final {
    double temperature;
    double humidity;
    double uvIndex;
    double visibility;
    double cloudiness;
    double windSpeed;
    QString condition;
};

#endif // WEATHERDATATYPES_H
