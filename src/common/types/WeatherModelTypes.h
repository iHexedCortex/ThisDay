#ifndef WEATHERMODELTYPES_H
#define WEATHERMODELTYPES_H

#include <QObject>
#include <QString>
#include <QList>

struct WeatherHourlyForecastUnitModel final {
    Q_GADGET

    Q_PROPERTY(QString time MEMBER time)
    Q_PROPERTY(QString temperature MEMBER temperature)
    Q_PROPERTY(QString icon MEMBER icon)
    Q_PROPERTY(QString humidity MEMBER humidity)

public:
    bool operator==(const WeatherHourlyForecastUnitModel &) const = default;

    QString time;
    QString icon;
    QString temperature;
    QString humidity;
};
Q_DECLARE_METATYPE(WeatherHourlyForecastUnitModel)

struct WeatherDailyForecastUnitModel final {
    Q_GADGET

    Q_PROPERTY(QString week MEMBER week)
    Q_PROPERTY(QString maxTemperature MEMBER maxTemperature)
    Q_PROPERTY(QString minTemperature MEMBER minTemperature)
    Q_PROPERTY(QString icon MEMBER icon)
    Q_PROPERTY(QString condition MEMBER condition)

public:
    bool operator==(const WeatherDailyForecastUnitModel &) const = default;

    QString week;
    QString maxTemperature;
    QString minTemperature;
    QString icon;
    QString condition;
};
Q_DECLARE_METATYPE(WeatherDailyForecastUnitModel)

struct WeatherHeroModel final {
    Q_GADGET

    Q_PROPERTY(QString temperature MEMBER temperature)
    Q_PROPERTY(QString maxTemperature MEMBER maxTemperature)
    Q_PROPERTY(QString minTemperature MEMBER minTemperature)
    Q_PROPERTY(QString feelsLikeTemperature MEMBER feelsLikeTemperature)
    Q_PROPERTY(QString icon MEMBER icon)
    Q_PROPERTY(QString condition MEMBER condition)

public:
    bool operator==(const WeatherHeroModel &) const = default;

    QString temperature;
    QString maxTemperature;
    QString minTemperature;
    QString feelsLikeTemperature;
    QString icon;
    QString condition;
};
Q_DECLARE_METATYPE(WeatherHeroModel)

struct WeatherMetricsModel final {
    Q_GADGET

    Q_PROPERTY(QString windSpeed MEMBER windSpeed)
    Q_PROPERTY(QString windDirection MEMBER windDirection)
    Q_PROPERTY(QString humidity MEMBER humidity)
    Q_PROPERTY(QString pressure MEMBER pressure)
    Q_PROPERTY(QString dewPoint MEMBER dewPoint)
    Q_PROPERTY(QString precipitation MEMBER precipitation)
    Q_PROPERTY(QString visibility MEMBER visibility)
    Q_PROPERTY(QString uvLevel MEMBER uvLevel)
    Q_PROPERTY(int uvIndex MEMBER uvIndex)
    Q_PROPERTY(QString cloudiness MEMBER cloudiness)

public:
    bool operator==(const WeatherMetricsModel &) const = default;

    QString windSpeed;
    QString windDirection;
    QString humidity;
    QString pressure;
    QString dewPoint;
    QString precipitation;
    QString visibility;
    QString uvLevel;
    int uvIndex;
    QString cloudiness;
};
Q_DECLARE_METATYPE(WeatherMetricsModel)

struct WeatherAstronomyModel final {
    Q_GADGET

    Q_PROPERTY(QString sunrise MEMBER sunrise)
    Q_PROPERTY(QString sunset MEMBER sunset)

public:
    bool operator==(const WeatherAstronomyModel &) const = default;

    QString sunrise;
    QString sunset;
};
Q_DECLARE_METATYPE(WeatherAstronomyModel)

struct WeatherTimelineModel final {
    Q_GADGET

    Q_PROPERTY(QList<WeatherHourlyForecastUnitModel> hourlyForecastModel MEMBER hourlyForecastModel)
    Q_PROPERTY(QList<WeatherDailyForecastUnitModel> dailyForecastModel MEMBER dailyForecastModel)

public:
    bool operator==(const WeatherTimelineModel &) const = default;

    QList<WeatherHourlyForecastUnitModel> hourlyForecastModel;
    QList<WeatherDailyForecastUnitModel> dailyForecastModel;
};
Q_DECLARE_METATYPE(WeatherTimelineModel)

#endif // WEATHERMODELTYPES_H
