#include "WeatherProvider.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QNetworkRequest>
#include <QJsonArray>

WeatherProvider::WeatherProvider(QObject *parent) : QObject{parent} {
    this->manager = new QNetworkAccessManager(this);
    this->locationProvider = new LocationProvider(this);

    this->setDefaultDataValues();

    this->connect(this->locationProvider, &LocationProvider::coordinatesFound, this, &WeatherProvider::onCoordinatesFound);
    this->connect(this->manager, &QNetworkAccessManager::finished, this, &WeatherProvider::onWeatherFetched);
}

void WeatherProvider::fetchWeather(const QString &city) {
    this->setWeatherDataLoading(true);
    this->setWeatherDetailsDataLoading(true);
    this->setForecastDataLoading(true);

    this->locationProvider->searchCity(city);
}

void WeatherProvider::updateWeather() {
    this->fetchWeather(this->locationProvider->getCity());
}

void WeatherProvider::onWeatherFetched(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonObject json = QJsonDocument::fromJson(reply->readAll()).object();

        this->extractCurrentInformationFromJson(json["current"].toObject());
        this->extractHourlyForecastFromJson(json["hourly"].toObject());
        this->extractDailyForecastFromJson(json["daily"].toObject());

        emit this->weatherDataChanged();
        emit this->forecastDataChanged();
        emit this->weatherDetailsDataChanged();

        this->setWeatherDataLoading(false);
        this->setForecastDataLoading(false);
        this->setWeatherDetailsDataLoading(false);
    } else {
        qDebug() << "Open-Meteo Error:" << reply->errorString();
    }

    reply->deleteLater();
}

void WeatherProvider::onCoordinatesFound(double latitude, double longitude) {
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
    this->updateLastFetchedDateTime();
}

void WeatherProvider::setDefaultDataValues() {
    static const int defaultIntValue = -999;
    static const double defaultDoubleValue = -999.0;
    static const QString defaultStringValue = "Loading...";
    static const bool defaultLoadingValue = false;

    this->temperature = defaultDoubleValue;
    this->maxTemperature = defaultDoubleValue;
    this->minTemperature = defaultDoubleValue;
    this->feelsLike = defaultDoubleValue;
    this->humidity = defaultIntValue;
    this->windSpeed = defaultDoubleValue;
    this->windDirection = "--";
    this->pressure = defaultIntValue;
    this->cloudiness = defaultIntValue;
    this->visibility = defaultDoubleValue;
    this->dewPoint = defaultDoubleValue;
    this->precipitation = defaultDoubleValue;
    this->uvLevel = defaultStringValue;
    this->uvIndex = defaultIntValue;
    this->condition = defaultStringValue;
    this->sunrise = defaultStringValue;
    this->sunset = defaultStringValue;
    this->latitude = defaultDoubleValue;
    this->longitude = defaultDoubleValue;
    this->hourlyForecastModel = {};
    this->dailyForecastModel = {};
    this->lastFetchedTime = defaultStringValue;
    this->weatherDataLoading = defaultLoadingValue;
    this->forecastDataLoading = defaultLoadingValue;
    this->weatherDetailsDataLoading = defaultLoadingValue;
}

double WeatherProvider::getTemperature() const {
    return this->temperature;
}

double WeatherProvider::getMaxTemperature() const {
    return this->maxTemperature;
}

double WeatherProvider::getMinTemperature() const {
    return this->minTemperature;
}

double WeatherProvider::getFeelsLike() const {
    return this->feelsLike;
}

QString WeatherProvider::getCondition() const {
    return this->condition;
}

QString WeatherProvider::getDescription() const {
    return this->description;
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

HourlyForecastModel WeatherProvider::getHourlyForecastModel() const {
    return this->hourlyForecastModel;
}

DailyForecastModel WeatherProvider::getDailyForecastModel() const {
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

void WeatherProvider::extractCurrentInformationFromJson(const QJsonObject &json) {
    this->temperature = json["temperature_2m"].toDouble();
    this->feelsLike = json["apparent_temperature"].toDouble();
    this->humidity = json["relative_humidity_2m"].toInt();
    this->pressure = json["pressure_msl"].toInt();
    this->windSpeed = json["wind_speed_10m"].toDouble();
    this->cloudiness = json["cloud_cover"].toInt();
    this->precipitation = json["precipitation"].toDouble();

    const int degrees = json["wind_direction_10m"].toInt();
    static const QStringList sectors = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
    this->windDirection = sectors[static_cast<int>((degrees + 22.5) / 45.0) % 8];

    this->condition = this->getConditionFromWmo(json["weather_code"].toInt());
}

void WeatherProvider::extractHourlyForecastFromJson(const QJsonObject &json) {
    QJsonArray times = json["time"].toArray();
    QJsonArray temps = json["temperature_2m"].toArray();
    QJsonArray humidities = json["relative_humidity_2m"].toArray();
    QJsonArray codes = json["weather_code"].toArray();
    QJsonArray visibilities = json["visibility"].toArray();
    QJsonArray dewPoints = json["dew_point_2m"].toArray();

    this->hourlyForecastModel.clear();

    const int currentHour = QDateTime::currentDateTime().time().hour();

    for (int i = currentHour; i < currentHour + 24; ++i) {
        if (i == currentHour) {
            this->visibility = visibilities[i].toDouble() / 1000.0;
            this->dewPoint = dewPoints[i].toDouble();

            continue;
        }

        HourlyForecastUnit unit;
        unit.time = QDateTime::fromString(times[i].toString(), Qt::ISODate).toString("HH:mm");
        unit.temperature = temps[i].toDouble();
        unit.humidity = humidities[i].toInt();
        unit.condition = this->getConditionFromWmo(codes[i].toInt());

        this->hourlyForecastModel.append(unit);
    }
}

void WeatherProvider::extractDailyForecastFromJson(const QJsonObject &json) {
    QJsonArray times = json["time"].toArray();
    QJsonArray maxTemps = json["temperature_2m_max"].toArray();
    QJsonArray minTemps = json["temperature_2m_min"].toArray();
    QJsonArray codes = json["weather_code"].toArray();
    QJsonArray uvIndices = json["uv_index_max"].toArray();
    QJsonArray sunrises = json["sunrise"].toArray();
    QJsonArray sunsets = json["sunset"].toArray();

    this->dailyForecastModel.clear();

    for (int i = 1; i < times.size(); ++i) {
        DailyForecastUnit unit;
        QDate date = QDate::fromString(times[i].toString(), "yyyy-MM-dd");

        this->maxTemperature = maxTemps[i].toDouble();
        this->minTemperature = minTemps[i].toDouble();
        this->uvIndex = qRound(uvIndices[i].toDouble());
        this->uvLevel = this->getUVLevelFromIndex(this->uvIndex);
        this->sunrise = QDateTime::fromString(sunrises[i].toString(), Qt::ISODate).toString("HH:mm");
        this->sunset = QDateTime::fromString(sunsets[i].toString(), Qt::ISODate).toString("HH:mm");

        if (date == QDate::currentDate().addDays(1))
            unit.week = "Tomorrow";
        else
            unit.week = date.toString("dddd");

        unit.maxTemperature = maxTemps[i].toDouble();
        unit.minTemperature = minTemps[i].toDouble();
        unit.condition = this->getConditionFromWmo(codes[i].toInt());

        this->dailyForecastModel.append(unit);
    }
}

QString WeatherProvider::getConditionFromWmo(int code) {
    switch (code) {
        case 0: return "Clear sky";
        case 1: case 2: return "Partly cloudy";
        case 3: return "Clouds";
        case 45: return (this->visibility > 1.0) ? "Mist" : "Foggy";
        case 48: return "Foggy";
        case 51: case 53: case 55: return "Drizzle";
        case 61: case 63: case 65: return "Rainy";
        case 66: case 67: return "Hail";
        case 71: case 73: case 75: return "Snowy";
        case 80: case 81: case 82: return "Rainy";
        case 95: return "Thunder";
        case 96: case 99: return "Thunderstorm";
        default: return "Clear sky";
    }
}

QString WeatherProvider::getUVLevelFromIndex(int index) {
    if (index < 3) return "Low";
    if (index < 6) return "Moderate";
    if (index < 8) return "High";
    if (index < 11) return "Very High";
    return "Extreme";
}
