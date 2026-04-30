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

private:
    QString date;

    friend class WeatherProvider;
};

using HourlyForecastModel = QList<HourlyForecastUnit>;
using DailyForecastModel = QList<DailyForecastUnit>;

class WeatherProvider final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double temperature READ getTemperature NOTIFY weatherDataChanged)
    Q_PROPERTY(double maxTemperature READ getMaxTemperature NOTIFY forecastDataChanged)
    Q_PROPERTY(double minTemperature READ getMinTemperature NOTIFY forecastDataChanged)
    Q_PROPERTY(double feelsLike READ getFeelsLike NOTIFY weatherDataChanged)
    Q_PROPERTY(QString condition READ getCondition NOTIFY weatherDataChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY weatherDataChanged)
    Q_PROPERTY(int humidity READ getHumidity NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(double windSpeed READ getWindSpeed NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString windDirection READ getWindDirection NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int pressure READ getPressure NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int cloudiness READ getCloudiness NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int visibility READ getVisibility NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(double dewPoint READ getDewPoint NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int precipitation READ getPrecipitation NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int uvIndex READ getUVIndex NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString uvLevel READ getUVLevel NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(QString sunrise READ getSunrise NOTIFY weatherDataChanged)
    Q_PROPERTY(QString sunset READ getSunset NOTIFY weatherDataChanged)
    Q_PROPERTY(QString city READ getCity NOTIFY weatherDataChanged)
    Q_PROPERTY(HourlyForecastModel hourlyForecastModel READ getHourlyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(DailyForecastModel dailyForecastModel READ getDailyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(QString lastFetchedTime READ getLastFetchedTime NOTIFY weatherDataChanged)
    Q_PROPERTY(bool weatherDataLoading READ getWeatherDataLoading NOTIFY weatherDataLoadingChanged)
    Q_PROPERTY(bool weatherDetailsDataLoading READ getWeatherDetailsDataLoading NOTIFY weatherDetailsDataLoadingChanged)
    Q_PROPERTY(bool forecastDataLoading READ getForecastDataLoading NOTIFY forecastDataLoadingChanged)

public:
    explicit WeatherProvider(QObject *parent = nullptr);

    double getTemperature() const;
    double getMaxTemperature() const;
    double getMinTemperature() const;
    double getFeelsLike() const;
    int getHumidity() const;
    double getWindSpeed() const;
    QString getWindDirection() const;
    int getPressure() const;
    int getCloudiness() const;
    double getVisibility() const;
    double getDewPoint() const;
    double getPrecipitation() const;
    QString getUVLevel() const;
    int getUVIndex() const;
    QString getCondition() const;
    QString getDescription() const;
    QString getSunrise() const;
    QString getSunset() const;
    QString getCity() const;
    HourlyForecastModel getHourlyForecastModel() const;
    DailyForecastModel getDailyForecastModel() const;
    QString getLastFetchedTime() const;
    bool getWeatherDataLoading() const;
    bool getWeatherDetailsDataLoading() const;
    bool getForecastDataLoading() const;

    Q_INVOKABLE void fetchWeather(const QString &city);
    Q_INVOKABLE void updateWeather();

signals:
    void weatherDataChanged();
    void forecastDataChanged();
    void weatherDetailsDataChanged();
    void weatherDataLoadingChanged();
    void forecastDataLoadingChanged();
    void weatherDetailsDataLoadingChanged();

private slots:
    void onResponse(QNetworkReply *reply);

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
    QString city;
    double latitude;
    double longtitude;
    HourlyForecastModel hourlyForecastModel;
    DailyForecastModel dailyForecastModel;
    QString lastFetchedTime;
    bool weatherDataLoading;
    bool forecastDataLoading;
    bool weatherDetailsDataLoading;

    void setDefaultDataValues();
    void setWeatherDataLoading(bool newState);
    void setForecastDataLoading(bool newState);
    void setWeatherDetailsDataLoading(bool newState);

    void updateLastFetchedDateTime();

    void extractMainInformationFromJson(const QJsonObject &json);
    void extractSysInformationFromJson(const QJsonObject &json);
    void extractRainInformationFromJson(const QJsonObject &json);
    void extractOtherInformationFromJson(const QJsonObject &json);
    void extractWindInformationFromJson(const QJsonObject &json);
    void extractCloudInformationFromJson(const QJsonObject &json);
    void extractCoordinateInformationFromJson(const QJsonObject &json);
    void extractUVInformationFromJson(const QJsonObject &json);
    void extractHourlyForecastFromJson(const QJsonObject &json);
    void extractDailyForecastFromJson(const QJsonObject &json);
};

#endif // WEATHERPROVIDER_H
