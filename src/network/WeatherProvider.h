#ifndef WEATHERPROVIDER_H
#define WEATHERPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVariantList>

class WeatherProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int temperature READ getTemperature NOTIFY weatherDataChanged)
    Q_PROPERTY(int maxTemperature READ getMaxTemperature NOTIFY weatherDataChanged)
    Q_PROPERTY(int minTemperature READ getMinTemperature NOTIFY weatherDataChanged)
    Q_PROPERTY(int feelsLike READ getFeelsLike NOTIFY weatherDataChanged)
    Q_PROPERTY(QString condition READ getCondition NOTIFY weatherDataChanged)
    Q_PROPERTY(int humidity READ getHumidity NOTIFY weatherDetailsDataChanged)
    Q_PROPERTY(int windSpeed READ getWindSpeed NOTIFY weatherDetailsDataChanged)
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
    Q_PROPERTY(QVariantList hourlyForecastModel READ getHourlyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(QVariantList dailyForecastModel READ getDailyForecastModel NOTIFY forecastDataChanged)
    Q_PROPERTY(QString lastFetchedTime READ getLastFetchedTime NOTIFY weatherDataChanged)
    Q_PROPERTY(bool weatherDataLoading READ getWeatherDataLoading NOTIFY weatherDataLoadingChanged)
    Q_PROPERTY(bool weatherDetailsDataLoading READ getWeatherDetailsDataLoading NOTIFY weatherDetailsDataLoadingChanged)
    Q_PROPERTY(bool forecastDataLoading READ getForecastDataLoading NOTIFY forecastDataLoadingChanged)

public:
    explicit WeatherProvider(QObject *parent = nullptr);

    int getTemperature() const;
    int getMaxTemperature() const;
    int getMinTemperature() const;
    int getFeelsLike() const;
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
    QString getSunrise() const;
    QString getSunset() const;
    QString getCity() const;
    QVariantList getHourlyForecastModel() const;
    QVariantList getDailyForecastModel() const;
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

    int temperature;
    int maxTemperature;
    int minTemperature;
    int feelsLike;
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
    QString sunrise;
    QString sunset;
    QString city;
    double latitude;
    double longtitude;
    QVariantList hourlyForecastModel;
    QVariantList dailyForecastModel;
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
