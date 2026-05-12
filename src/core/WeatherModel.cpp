#include "WeatherModel.h"

#include "../common/builders/WeatherSummaryBuilder.h"
#include "../common/mappers/WeatherMapper.h"
#include "../common/types/WeatherPresentationSettings.h"

WeatherModel::WeatherModel(WeatherProvider *provider, SettingsManager *settings, QObject *parent)
    : QObject(parent), provider(provider), settings(settings)
{
    this->connect(this->provider, &WeatherProvider::weatherFetched, this, &WeatherModel::onWeatherFetched);
}

void WeatherModel::onWeatherFetched(const QJsonObject &json) {
    this->rawHero = WeatherParser::parseHero(json);
    this->rawMetrics = WeatherParser::parseMetrics(json);
    this->rawAstronomy = WeatherParser::parseAstronomy(json);
    this->rawTimeline = WeatherParser::parseTimeline(json);

    WeatherPresentationSettings presentationSettings;
    presentationSettings.temperatureUnit = this->settings->getTemperatureUnit();
    presentationSettings.windSpeedUnit = this->settings->getWindSpeedUnit();
    presentationSettings.precipitationUnit = this->settings->getPrecipitationUnit();

    this->hero = WeatherMapper::mapHero(this->rawHero, this->rawAstronomy, presentationSettings);
    this->provider->setIsHeroLoading(false);
    emit this->heroChanged();

    this->metrics = WeatherMapper::mapMetrics(this->rawMetrics, presentationSettings);
    this->provider->setIsMetricsLoading(false);
    emit this->metricsChanged();

    this->astronomy = WeatherMapper::mapAstronomy(this->rawAstronomy, presentationSettings);
    this->provider->setIsAstronomyLoading(false);
    emit this->astronomyChanged();

    this->timeline = WeatherMapper::mapTimeline(this->rawTimeline, this->rawAstronomy, presentationSettings);
    this->provider->setIsTimelineLoading(false);
    emit this->timelineChanged();

    WeatherSummaryData summaryData;
    summaryData.cloudiness = this->rawMetrics.cloudiness;
    summaryData.condition = this->hero.condition;
    summaryData.humidity = this->rawMetrics.humidity;
    summaryData.visibility = this->rawMetrics.visibility / 1000;
    summaryData.uvIndex = this->rawMetrics.uvIndex;
    summaryData.windSpeed = this->rawMetrics.windSpeed;
    summaryData.temperature = this->rawHero.temperature;

    this->summary = WeatherSummaryBuilder::build(summaryData);
    emit this->summaryChanged();
}
