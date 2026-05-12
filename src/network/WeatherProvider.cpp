#include "WeatherProvider.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QNetworkRequest>
#include <QJsonArray>

WeatherProvider::WeatherProvider(QObject *parent) : QObject{parent} {
    this->manager = new QNetworkAccessManager(this);

    this->connect(this->manager, &QNetworkAccessManager::finished, this, &WeatherProvider::onResponse);
}

void WeatherProvider::fetchWeather(double latitude, double longitude) {
    this->setIsHeroLoading(true);
    this->setIsMetricsLoading(true);
    this->setIsAstronomyLoading(true);
    this->setIsTimelineLoading(true);

    this->latitude = latitude;
    this->longitude = longitude;

    const QString url = QString(
        "https://api.open-meteo.com/v1/forecast?"
        "latitude=%1&longitude=%2"
        "&current=temperature_2m,relative_humidity_2m,apparent_temperature,precipitation,weather_code,cloud_cover,pressure_msl,surface_pressure,wind_speed_10m,wind_direction_10m"
        "&hourly=temperature_2m,relative_humidity_2m,weather_code,visibility,dew_point_2m"
        "&daily=weather_code,temperature_2m_max,temperature_2m_min,sunrise,sunset,uv_index_max"
        "&timezone=auto&forecast_days=7"
    ).arg(this->latitude).arg(this->longitude);

    this->manager->get(QNetworkRequest(QUrl(url)));
    this->updateFetchedAt();
}

void WeatherProvider::updateWeather() {
    this->fetchWeather(this->latitude, this->longitude);
}

void WeatherProvider::onResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();

        emit this->weatherFetched(json);
    } else {
        qDebug() << "Api Error:" << reply->errorString();
    }

    reply->deleteLater();

    this->setIsHeroLoading(false);
    this->setIsMetricsLoading(false);
    this->setIsAstronomyLoading(false);
    this->setIsTimelineLoading(false);
}

void WeatherProvider::updateFetchedAt() {
    this->fetchedAt = QTime::currentTime().currentTime().toString("HH:mm");
}

void WeatherProvider::setIsHeroLoading(bool newState) {
    if (this->isHeroLoading == newState) return;
    this->isHeroLoading = newState;

    emit this->isHeroLoadingChanged();
}

void WeatherProvider::setIsMetricsLoading(bool newState) {
    if (this->isMetricsLoading == newState) return;
    this->isMetricsLoading = newState;

    emit this->isMetricsLoadingChanged();
}

void WeatherProvider::setIsAstronomyLoading(bool newState) {
    if (this->isAstronomyLoading == newState) return;
    this->isAstronomyLoading = newState;

    emit this->isAstronomyLoadingChanged();
}

void WeatherProvider::setIsTimelineLoading(bool newState) {
    if (this->isTimelineLoading == newState) return;
    this->isTimelineLoading = newState;

    emit this->isTimelineLoadingChanged();
}
