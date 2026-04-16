#include "WeatherProvider.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QNetworkRequest>
#include <QJsonArray>

WeatherProvider::WeatherProvider(QObject *parent) : QObject{parent} {
    this->manager = new QNetworkAccessManager(this);
    this->setIsLoading(true);
    this->connect(this->manager, &QNetworkAccessManager::finished, this, &WeatherProvider::onResult);
}

void WeatherProvider::fetchWeather(const QString &city) {
    const QString apiKey = "5c4fc22e4976b520885e207e94e1bf5d";

    QUrl weatherUrl(QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
                    .arg(city, apiKey));
    QUrl forecastUrl(QString("https://api.openweathermap.org/data/2.5/forecast?q=%1&appid=%2&units=metric")
                    .arg(city, apiKey));

    this->city = city;
    this->setIsLoading(true);

    this->manager->get(QNetworkRequest(weatherUrl));
    this->manager->get(QNetworkRequest(forecastUrl));
}

void WeatherProvider::updateWeather() {
    this->fetchWeather(this->city);
}

void WeatherProvider::onResult(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = jsonDocument.object();

        if (json.contains("list")) {
            this->extractHourlyForecastFromJson(json);
            this->extractDailyForecastFromJson(json);
        }
        else if (json.contains("main")) {
            this->extractMainInformationFromJson(json);
            this->extractSysInformationFromJson(json);
            this->extractCloudInformationFromJson(json);
            this->extractWindInformationFromJson(json);
            this->extractRainInformationFromJson(json);
            this->extractOtherInformationFromJson(json);
        }

        emit dataChanged();
    } else {
        qDebug() << "API Error:" << reply->errorString();
    }

    this->setIsLoading(false);
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

QString WeatherProvider::getIconCode() const {
    return this->iconCode;
}

QVariantList WeatherProvider::getHourlyForecastModel() const {
    return this->hourlyForecastModel;
}

QVariantList WeatherProvider::getDailyForecastModel() const {
    return this->dailyForecastModel;
}

bool WeatherProvider::getIsLoading() const {
    return this->isLoading;
}

void WeatherProvider::setIsLoading(bool newState) {
    this->isLoading = newState;

    emit this->loadingChanged();
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
}

void WeatherProvider::extractCloudInformationFromJson(const QJsonObject &json) {
    QJsonObject cloudObj = json["clouds"].toObject();

    this->cloudiness = cloudObj["all"].toInt();
}

void WeatherProvider::extractOtherInformationFromJson(const QJsonObject &json) {
    this->uvIndex = 4;
    this->uvLevel = (this->uvIndex >= 6.0) ? "High" : (this->uvIndex >= 3.0) ? "Moderate" : "Low";

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
