#ifndef WEATHERPROVIDER_H
#define WEATHERPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVariantList>

class WeatherProvider : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int temperature READ getTemperature NOTIFY dataChanged)
    Q_PROPERTY(int maxTemperature READ getMaxTemperature NOTIFY dataChanged)
    Q_PROPERTY(int minTemperature READ getMinTemperature NOTIFY dataChanged)
    Q_PROPERTY(int feelsLike READ getFeelsLike NOTIFY dataChanged)
    Q_PROPERTY(QString condition READ getCondition NOTIFY dataChanged)
    Q_PROPERTY(int humidity READ getHumidity NOTIFY dataChanged)
    Q_PROPERTY(int windSpeed READ getWindSpeed NOTIFY dataChanged)
    Q_PROPERTY(QString windDirection READ getWindDirection NOTIFY dataChanged)
    Q_PROPERTY(int pressure READ getPressure NOTIFY dataChanged)
    Q_PROPERTY(int cloudiness READ getCloudiness NOTIFY dataChanged)
    Q_PROPERTY(int visibility READ getVisibility NOTIFY dataChanged)
    Q_PROPERTY(double dewPoint READ getDewPoint NOTIFY dataChanged)
    Q_PROPERTY(int precipitation READ getPrecipitation NOTIFY dataChanged)
    Q_PROPERTY(int uvIndex READ getUVIndex NOTIFY dataChanged)
    Q_PROPERTY(QString uvLevel READ getUVLevel NOTIFY dataChanged)
    Q_PROPERTY(QString sunrise READ getSunrise NOTIFY dataChanged)
    Q_PROPERTY(QString sunset READ getSunset NOTIFY dataChanged)
    Q_PROPERTY(QString city READ getCity NOTIFY dataChanged)
    Q_PROPERTY(QVariantList hourlyForecastModel READ getHourlyForecastModel NOTIFY dataChanged)
    Q_PROPERTY(QVariantList dailyForecastModel READ getDailyForecastModel NOTIFY dataChanged)
    Q_PROPERTY(bool isLoading READ getIsLoading NOTIFY loadingChanged)
    Q_PROPERTY(QString lastFetchedTime READ getLastFetchedTime NOTIFY dataChanged)

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
    bool getIsLoading() const;
    QString getLastFetchedTime() const;

    Q_INVOKABLE void fetchWeather(const QString &city);
    Q_INVOKABLE void updateWeather();

signals:
    void dataChanged();
    void loadingChanged();

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

    int temperature = -999;
    int maxTemperature = -999;
    int minTemperature = -999;
    int feelsLike = -999;
    int humidity = -999;
    double windSpeed = -999;
    QString windDirection = "--";
    int pressure = -999;
    int cloudiness = -999;
    double visibility = -999;
    double dewPoint = -999;
    double precipitation = -999;
    QString uvLevel = "Loading...";
    int uvIndex = -999;
    QString condition = "Loading...";
    QString sunrise = "--:--";
    QString sunset = "--:--";
    QString city = "Detecting...";
    double latitude = -999;
    double longtitude = -999;
    QVariantList hourlyForecastModel;
    QVariantList dailyForecastModel;
    bool isLoading = false;
    QString lastFetchedTime = "--:--";

    void setIsLoading(bool newState);
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
