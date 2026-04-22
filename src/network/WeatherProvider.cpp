#include "WeatherProvider.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QNetworkRequest>
#include <QJsonArray>

#include "../config/SecretConfig.h"

WeatherProvider::WeatherProvider(QObject *parent) : QObject{parent} {
    this->manager = new QNetworkAccessManager(this);
    this->connect(this->manager, &QNetworkAccessManager::finished, this, &WeatherProvider::onResponse);
}

void WeatherProvider::fetchWeather(const QString &city) {
    const QString API_KEY = SecretConfig::OPENWEATHER_API_KEY;

    this->city = city;

    this->setWeatherDataLoading(true);
    this->setWeatherDetailsDataLoading(true);
    this->setForecastDataLoading(true);

    QUrl weatherUrl(QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
                    .arg(city, API_KEY));
    this->manager->get(QNetworkRequest(weatherUrl));

    QUrl forecastUrl(QString("https://api.openweathermap.org/data/2.5/forecast?q=%1&appid=%2&units=metric")
                    .arg(city, API_KEY));
    this->manager->get(QNetworkRequest(forecastUrl));

    this->updateLastFetchedDateTime();
}

void WeatherProvider::updateWeather() {
    this->fetchWeather(this->city);
}

void WeatherProvider::onResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = jsonDocument.object();

        if (json.contains("list")) {
            this->extractHourlyForecastFromJson(json);
            this->extractDailyForecastFromJson(json);

            emit this->forecastDataChanged();
            this->setForecastDataLoading(false);
        }
        else if (json.contains("main")) {
            this->extractMainInformationFromJson(json);
            this->extractSysInformationFromJson(json);
            this->extractCloudInformationFromJson(json);
            this->extractWindInformationFromJson(json);
            this->extractRainInformationFromJson(json);
            this->extractCoordinateInformationFromJson(json);
            this->extractOtherInformationFromJson(json);

            emit this->weatherDataChanged();
            this->setWeatherDataLoading(false);

            const QString API_KEY = SecretConfig::OPENWEATHER_API_KEY;
            QUrl uvUrl(QString("https://api.openweathermap.org/data/2.5/uvi?lat=%1&lon=%2&appid=%3")
                           .arg(this->latitude).arg(this->longtitude).arg(API_KEY));
            this->manager->get(QNetworkRequest(uvUrl));
        }
        else if (json.contains("value")) {
            this->extractUVInformationFromJson(json);

            emit this->weatherDetailsDataChanged();
            this->setWeatherDetailsDataLoading(false);
        }
    } else {
        qDebug() << "API Error:" << reply->errorString();
    }

    reply->deleteLater();
}

int WeatherProvider::getTemperature() const {
    return this->temperature;
}

int WeatherProvider::getMaxTemperature() const {
    return this->maxTemperature;
}

int WeatherProvider::getMinTemperature() const {
    return this->minTemperature;
}

int WeatherProvider::getFeelsLike() const {
    return this->feelsLike;
}

QString WeatherProvider::getCondition() const {
    return this->condition;
}

int WeatherProvider::getHumidity() const {
    return this->humidity;
}

double WeatherProvider::getWindSpeed() const {
    return this->windSpeed;
}

QString WeatherProvider::getWindDirection() const {
    return this->windDirection;
}

int WeatherProvider::getPressure() const {
    return this->pressure;
}

int WeatherProvider::getCloudiness() const {
    return this->cloudiness;
}

double WeatherProvider::getVisibility() const {
    return this->visibility;
}

double WeatherProvider::getDewPoint() const {
    return this->dewPoint;
}

double WeatherProvider::getPrecipitation() const {
    return this->precipitation;
}

QString WeatherProvider::getUVLevel() const {
    return this->uvLevel;
}

int WeatherProvider::getUVIndex() const {
    return this->uvIndex;
}

QString WeatherProvider::getSunrise() const {
    return this->sunrise;
}

QString WeatherProvider::getSunset() const {
    return this->sunset;
}

QString WeatherProvider::getCity() const {
    return this->city;
}

QVariantList WeatherProvider::getHourlyForecastModel() const {
    return this->hourlyForecastModel;
}

QVariantList WeatherProvider::getDailyForecastModel() const {
    return this->dailyForecastModel;
}

QString WeatherProvider::getLastFetchedTime() const {
    return this->lastFetchedTime;
}

bool WeatherProvider::getWeatherDataLoading() const {
    return this->weatherDataLoading;
}

bool WeatherProvider::getWeatherDetailsDataLoading() const {
    return this->weatherDetailsDataLoading;
}

bool WeatherProvider::getForecastDataLoading() const {
    return this->forecastDataLoading;
}

void WeatherProvider::setWeatherDataLoading(bool newState) {
    this->weatherDataLoading = newState;
    emit this->weatherDataLoadingChanged();
}


void WeatherProvider::setWeatherDetailsDataLoading(bool newState) {
    this->weatherDetailsDataLoading = newState;
    emit this->weatherDetailsDataLoadingChanged();
}

void WeatherProvider::setForecastDataLoading(bool newState) {
    this->forecastDataLoading = newState;
    emit this->forecastDataLoadingChanged();
}

void WeatherProvider::updateLastFetchedDateTime() {
    QTime currentTime = QTime::currentTime();

    this->lastFetchedTime = currentTime.toString("HH:mm");
}

void WeatherProvider::extractMainInformationFromJson(const QJsonObject &json) {
    QJsonObject mainObj = json["main"].toObject();

    this->temperature = static_cast<int>(mainObj["temp"].toDouble());
    this->feelsLike = static_cast<int>(mainObj["feels_like"].toDouble());
    this->humidity = mainObj["humidity"].toInt();
    this->pressure = mainObj["pressure"].toInt();
    this->dewPoint = qRound(this->temperature - ((100 - this->humidity) / 5.0));
}

void WeatherProvider::extractSysInformationFromJson(const QJsonObject &json) {
    QJsonObject sysObj = json["sys"].toObject();

    qint64 sunriseRaw = sysObj["sunrise"].toVariant().toLongLong();
    qint64 sunsetRaw = sysObj["sunset"].toVariant().toLongLong();

    this->sunrise = QDateTime::fromSecsSinceEpoch(sunriseRaw).toString("hh:mm");
    this->sunset = QDateTime::fromSecsSinceEpoch(sunsetRaw).toString("hh:mm");
}

void WeatherProvider::extractRainInformationFromJson(const QJsonObject &json) {
    QJsonObject rainObj = json["rain"].toObject();

    this->precipitation = qRound(rainObj["3h"].toDouble());
}

void WeatherProvider::extractWindInformationFromJson(const QJsonObject &json) {
    QJsonObject windObj = json["wind"].toObject();

    this->windSpeed = windObj["speed"].toDouble();

    const int degrees = windObj["deg"].toInt();
    static const QStringList sectors = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    int sectorIndex = static_cast<int>((degrees + 22.5) / 45.0) % sectors.length();
    this->windDirection = sectors[sectorIndex];
}

void WeatherProvider::extractCoordinateInformationFromJson(const QJsonObject &json) {
    QJsonObject coordObj = json["coord"].toObject();

    this->latitude = coordObj["lat"].toDouble();
    this->longtitude = coordObj["lon"].toDouble();
}

void WeatherProvider::extractCloudInformationFromJson(const QJsonObject &json) {
    QJsonObject cloudObj = json["clouds"].toObject();

    this->cloudiness = cloudObj["all"].toInt();
}

void WeatherProvider::extractUVInformationFromJson(const QJsonObject &json) {
    this->uvIndex = qRound(json["value"].toDouble());

    if (this->uvIndex < 3) this->uvLevel = "Low";
    else if (this->uvIndex < 6) this->uvLevel = "Moderate";
    else if (this->uvIndex < 8) this->uvLevel = "High";
    else if (this->uvIndex < 11) this->uvLevel = "Very High";
    else this->uvLevel = "Extreme";
}

void WeatherProvider::extractOtherInformationFromJson(const QJsonObject &json) {
    this->visibility = qRound(json["visibility"].toDouble() / 1000.0);

    QJsonArray weatherArray = json["weather"].toArray();
    if (!weatherArray.isEmpty()) {
        QJsonObject weatherObj = weatherArray[0].toObject();
        this->condition = weatherObj["main"].toString();
    }
}

void WeatherProvider::extractHourlyForecastFromJson(const QJsonObject &json) {
    QJsonArray list = json["list"].toArray();
    QVariantList model;

    int dailyHigh = -999;
    int dailyLow = 999;

    for (int i = 2; i < 10; i++) {
        QJsonObject item = list[i].toObject();
        QJsonObject mainObj = item["main"].toObject();

        QVariantMap map;

        QString dateTime = item["dt_txt"].toString();
        QString time = dateTime.split(" ")[1].left(5);

        map["time"] = time;
        map["temperature"] = static_cast<int>(mainObj["temp"].toDouble());
        map["humidity"] = mainObj["humidity"].toInt();

        QJsonArray weatherArray = item["weather"].toArray();
        if (!weatherArray.isEmpty()) {
            QJsonObject weatherObj = weatherArray[0].toObject();

            map["condition"] = weatherObj["main"].toString();
        }

        model.append(map);

        int temperature = static_cast<int>(mainObj["temp"].toDouble());
        if (temperature > dailyHigh)
            dailyHigh = temperature;
        if (temperature < dailyLow)
            dailyLow = temperature;
    }

    this->maxTemperature = dailyHigh;
    this->minTemperature = dailyLow;

    this->hourlyForecastModel = model;
}

void WeatherProvider::extractDailyForecastFromJson(const QJsonObject &json) {
    QJsonArray list = json["list"].toArray();

    struct DayStats {
        int maxTemperature = -999;
        int minTemperature = 999;
        QString condition;
    };

    QMap<QString, DayStats> map;
    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");

    for (const QJsonValue &value : list) {
        QJsonObject item = value.toObject();
        QString dateTime = item["dt_txt"].toString();
        QString date = dateTime.split(" ")[0];

        if (date == currentDate) continue;

        QJsonObject mainObj = item["main"].toObject();

        int currentMaxTemperature = static_cast<int>(mainObj["temp_max"].toDouble());
        int currentMinTemperature = static_cast<int>(mainObj["temp_min"].toDouble());

        DayStats &stats = map[date];
        if (currentMaxTemperature > stats.maxTemperature) stats.maxTemperature = currentMaxTemperature;
        if (currentMinTemperature < stats.minTemperature) stats.minTemperature = currentMinTemperature;

        QJsonObject weather = item["weather"].toArray()[0].toObject();

        stats.condition = weather["main"].toString();
    }

    QVariantList model;

    auto mapConstIterator = map.constBegin();
    bool isTomorrow = true;

    while (mapConstIterator != map.constEnd()) {
        QVariantMap dayData;
        QDate date = QDate::fromString(mapConstIterator.key(), "yyyy-MM-dd");

        if (isTomorrow) {
            dayData["week"] = "Tomorrow";
            isTomorrow = false;
        } else {
            dayData["week"] = date.toString("ddd");
        }

        dayData["maxTemperature"] = mapConstIterator.value().maxTemperature;
        dayData["minTemperature"] = mapConstIterator.value().minTemperature;
        dayData["condition"] = mapConstIterator.value().condition;

        model.append(dayData);
        ++mapConstIterator;
    }

    this->dailyForecastModel = model;
}
