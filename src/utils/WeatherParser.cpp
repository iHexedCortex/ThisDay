#include "WeatherParser.h"

#include <QDateTime>
#include <QJsonArray>
#include <QJsonValue>

WeatherHeroData WeatherParser::parseHero(const QJsonObject &json) {
    WeatherHeroData hero;

    const QJsonObject current = json["current"].toObject();
    if (current.isEmpty()) return hero;

    const QJsonObject daily = json["daily"].toObject();

    hero.temperature = current["temperature_2m"].toDouble();
    hero.maxTemperature = daily["temperature_2m_max"].toArray().at(0).toDouble();
    hero.minTemperature = daily["temperature_2m_min"].toArray().at(0).toDouble();
    hero.feelsLikeTemperature = current["apparent_temperature"].toDouble();
    hero.conditionCode = current["weather_code"].toInt();

    return hero;
}

WeatherMetricsData WeatherParser::parseMetrics(const QJsonObject &json) {
    WeatherMetricsData metrics;

    const QJsonObject current = json["current"].toObject();
    if (current.isEmpty()) return metrics;

    const QJsonObject daily = json["daily"].toObject();
    const QJsonObject hourly = json["hourly"].toObject();

    metrics.windSpeed = current["wind_speed_10m"].toDouble();
    metrics.windDirectionDeg = current["wind_direction_10m"].toDouble();
    metrics.humidity = current["relative_humidity_2m"].toInt();
    metrics.pressure = static_cast<int>(current["pressure_msl"].toDouble());
    metrics.cloudiness = current["cloud_cover"].toInt();
    metrics.precipitation = current["precipitation"].toDouble();

    metrics.uvIndex = qRound(daily["uv_index_max"].toArray().at(0).toDouble());
    metrics.visibility = hourly["visibility"].toArray().at(0).toDouble();
    metrics.dewPoint = hourly["dew_point_2m"].toArray().at(0).toDouble();

    return metrics;
}

WeatherAstronomyData WeatherParser::parseAstronomy(const QJsonObject &json) {
    WeatherAstronomyData astronomy;

    QJsonObject daily = json["daily"].toObject();

    if (daily.isEmpty()) return astronomy;

    astronomy.sunrise = daily["sunrise"].toArray().at(0).toString();
    astronomy.sunset = daily["sunset"].toArray().at(0).toString();

    return astronomy;
}

WeatherTimelineData WeatherParser::parseTimeline(const QJsonObject &json) {
    WeatherTimelineData timeline;

    const QJsonObject hourly = json["hourly"].toObject();
    const QJsonObject daily = json["daily"].toObject();

    if (hourly.isEmpty() || daily.isEmpty()) return timeline;

    const QJsonArray hourlyDateTimes = hourly["time"].toArray();
    const QJsonArray hourlyTemperatures = hourly["temperature_2m"].toArray();
    const QJsonArray hourlyHumidities = hourly["relative_humidity_2m"].toArray();
    const QJsonArray hourlyConditionCodes = hourly["weather_code"].toArray();

    const QString currentLocalTimeStr = json["current"].toObject()["time"].toString();
    const QDateTime currentLocalDt = QDateTime::fromString(currentLocalTimeStr, Qt::ISODate);

    int startHour = 0;
    for (int hour = 0; hour < hourlyDateTimes.size(); ++hour) {
        const QDateTime dt = QDateTime::fromString(hourlyDateTimes[hour].toString(), Qt::ISODate);
        if (dt >= currentLocalDt) {
            startHour = hour;
            break;
        }
    }

    for (int hour = startHour; hour < startHour + 24 && hour < hourlyDateTimes.size(); ++hour) {
        WeatherHourlyForecastUnitData unit;

        unit.dateTime = hourlyDateTimes[hour].toString();
        unit.temperature = hourlyTemperatures[hour].toDouble();
        unit.conditionCode = hourlyConditionCodes[hour].toInt();
        unit.humidity = hourlyHumidities[hour].toInt();

        timeline.hourlyForecast.append(unit);
    }

    const QJsonArray dailyDateTimes = daily["time"].toArray();
    const QJsonArray dailyMaxTemperatures = daily["temperature_2m_max"].toArray();
    const QJsonArray dailyMinTemperatures = daily["temperature_2m_min"].toArray();
    const QJsonArray dailyConditionCodes = daily["weather_code"].toArray();

    for (int day = 0; day < dailyDateTimes.size(); ++day) {
        WeatherDailyForecastUnitData unit;

        unit.dateTime = dailyDateTimes[day].toString();
        unit.conditionCode = dailyConditionCodes[day].toInt();
        unit.maxTemperature = dailyMaxTemperatures[day].toDouble();
        unit.minTemperature = dailyMinTemperatures[day].toDouble();

        timeline.dailyForecast.append(unit);
    }

    return timeline;
}
