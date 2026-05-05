#ifndef WEATHERPROVIDER_H
#define WEATHERPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVariantList>

struct HourlyForecastUnit final {
    Q_GADGET

    Q_PROPERTY(QString time MEMBER time)
    Q_PROPERTY(QString condition MEMBER condition)
    Q_PROPERTY(double temperature MEMBER temperature)
    Q_PROPERTY(int humidity MEMBER humidity)

public:
    QString time;
    QString condition;
    double temperature;
    int humidity;

    bool operator==(const HourlyForecastUnit& other) const {
        return time == other.time &&
            condition == other.condition &&
            qFuzzyCompare(temperature, other.temperature) &&
            humidity == other.humidity;
    }
};

struct DailyForecastUnit final {
    Q_GADGET

    Q_PROPERTY(QString week MEMBER week)
    Q_PROPERTY(QString condition MEMBER condition)
    Q_PROPERTY(double maxTemperature MEMBER maxTemperature)
    Q_PROPERTY(double minTemperature MEMBER minTemperature)
    Q_PROPERTY(QString description MEMBER description)

public:
    QString week;
    QString condition;
    double maxTemperature;
    double minTemperature;
    QString description;

    bool operator==(const DailyForecastUnit& other) const {
        return week == other.week &&
            condition == other.condition &&
            qFuzzyCompare(maxTemperature, other.maxTemperature) &&
            qFuzzyCompare(minTemperature, other.minTemperature) &&
            description == other.description;
    }

private:
    QString date;

    friend class WeatherProvider;
};

using HourlyForecastModel = QList<HourlyForecastUnit>;
using DailyForecastModel = QList<DailyForecastUnit>;

class WeatherProvider final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double temperature MEMBER temperature NOTIFY weatherDataChanged)
    Q_PROPERTY(double maxTemperature MEMBER maxTemperature NOTIFY forecastDataChanged)
    Q_PROPERTY(double minTemperature MEMBER minTemperature NOTIFY forecastDataChanged)
    Q_PROPERTY(double feelsLike MEMBER feelsLike NOTIFY weatherDataChanged)
    Q_PROPERTY(QString condition MEMBER condition NOTIFY weatherDataChanged)
    Q_PROPERTY(QString description MEMBER description NOTIFY weatherDataChanged)
    Q_PROPERTY(int humidity MEMBER humidity NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(double windSpeed MEMBER windSpeed NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString windDirection MEMBER windDirection NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int pressure MEMBER pressure NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int cloudiness MEMBER cloudiness NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int visibility MEMBER visibility NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(double dewPoint MEMBER dewPoint NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int precipitation MEMBER precipitation NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int uvIndex MEMBER uvIndex NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString uvLevel MEMBER uvLevel NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString sunrise MEMBER sunrise NOTIFY weatherDataChanged)
    Q_PROPERTY(QString sunset MEMBER sunset NOTIFY weatherDataChanged)
    Q_PROPERTY(HourlyForecastModel hourlyForecastModel MEMBER hourlyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(DailyForecastModel dailyForecastModel MEMBER dailyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(QString lastFetchedTime MEMBER lastFetchedTime NOTIFY weatherDataChanged)
    Q_PROPERTY(bool weatherDataLoading MEMBER weatherDataLoading NOTIFY weatherDataLoadingChanged)
    Q_PROPERTY(bool weatherDetailsDataLoading MEMBER weatherDetailsDataLoading NOTIFY weatherDetailsDataLoadingChanged)
    Q_PROPERTY(bool forecastDataLoading MEMBER forecastDataLoading NOTIFY forecastDataLoadingChanged)

public:
    explicit WeatherProvider(QObject *parent = nullptr);

    Q_INVOKABLE void fetchWeather(double latitude, double longitude);
    Q_INVOKABLE void updateWeather();

signals:
    void weatherDataChanged();
    void forecastDataChanged();
    void weatherDetailsDataChanged();
    void weatherDataLoadingChanged();
    void forecastDataLoadingChanged();
    void weatherDetailsDataLoadingChanged();

private slots:
    void onWeatherFetched(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

    double temperature;
    double maxTemperature;
    double minTemperature;
    double feelsLike;
    int humidity;
    double windSpeed;
    QString windDirection;
    int pressure;
    int cloudiness;
    double visibility;
    double dewPoint;
    double precipitation;
    QString uvLevel;
    int uvIndex;
    QString condition;
    QString description;
    QString sunrise;
    QString sunset;
    double latitude;
    double longitude;
    HourlyForecastModel hourlyForecastModel;
    DailyForecastModel dailyForecastModel;
    QString lastFetchedTime;
    bool weatherDataLoading;
    bool forecastDataLoading;
    bool weatherDetailsDataLoading;

    QString getConditionFromWmo(int code);
    QString getUVLevelFromIndex(int index);

    void setWeatherDataLoading(bool newState);
    void setForecastDataLoading(bool newState);
    void setWeatherDetailsDataLoading(bool newState);

    void updateLastFetchedDateTime();

    void extractCurrentInformationFromJson(const QJsonObject &json);
    void extractHourlyForecastFromJson(const QJsonObject &json);
    void extractDailyForecastFromJson(const QJsonObject &json);
};

#endif // WEATHERPROVIDER_H
