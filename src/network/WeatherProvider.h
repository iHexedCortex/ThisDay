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
    Q_PROPERTY(QString iconCode READ getIconCode NOTIFY dataChanged)
    Q_PROPERTY(QVariantList hourlyForecastModel READ getHourlyForecastModel NOTIFY dataChanged)
    Q_PROPERTY(QVariantList dailyForecastModel READ getDailyForecastModel NOTIFY dataChanged)
    Q_PROPERTY(bool isLoading READ getIsLoading NOTIFY loadingChanged)

public:
    explicit WeatherProvider(QObject *parent = nullptr);

    int getTemperature() const;
    int getMaxTemperature() const;
    int getMinTemperature() const;
    int getFeelsLike() const;
    int getHumidity() const;
    double getWindSpeed() const;
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
    QString getIconCode() const;
    QVariantList getHourlyForecastModel() const;
    QVariantList getDailyForecastModel() const;
    bool getIsLoading() const;

    Q_INVOKABLE void fetchWeather(const QString &city);
    Q_INVOKABLE void updateWeather();

signals:
    void dataChanged();
    void loadingChanged();

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

    int temperature = 0;
    int maxTemperature = 0;
    int minTemperature = 0;
    int feelsLike = 0;
    int humidity = 0;
    double windSpeed = 0;
    int pressure = 0;
    int cloudiness = 0;
    double visibility = 0.0;
    double dewPoint = 0.0;
    double precipitation = 0;
    QString uvLevel = "Unknown";
    int uvIndex = 0;
    QString condition = "Unknown";
    QString sunrise = "Unknown";
    QString sunset = "Unknown";
    QString city = "Not Defined";
    QString iconCode = "01n";
    QVariantList hourlyForecastModel;
    QVariantList dailyForecastModel;
    bool isLoading = false;

    void setIsLoading(bool newState);

    void extractMainInformationFromJson(const QJsonObject &json);
    void extractSysInformationFromJson(const QJsonObject &json);
    void extractRainInformationFromJson(const QJsonObject &json);
    void extractOtherInformationFromJson(const QJsonObject &json);
    void extractWindInformationFromJson(const QJsonObject &json);
    void extractCloudInformationFromJson(const QJsonObject &json);
    void extractHourlyForecastFromJson(const QJsonObject &json);
    void extractDailyForecastFromJson(const QJsonObject &json);
};

#endif // WEATHERPROVIDER_H
