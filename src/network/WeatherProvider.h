#ifndef WEATHERPROVIDER_H
#define WEATHERPROVIDER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QVariantList>

class WeatherProvider final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isHeroLoading MEMBER isHeroLoading NOTIFY isHeroLoadingChanged)
    Q_PROPERTY(bool isMetricsLoading MEMBER isMetricsLoading NOTIFY isMetricsLoadingChanged)
    Q_PROPERTY(bool isAstronomyLoading MEMBER isAstronomyLoading NOTIFY isAstronomyLoadingChanged)
    Q_PROPERTY(bool isTimelineLoading MEMBER isTimelineLoading NOTIFY isTimelineLoadingChanged)

public:
    explicit WeatherProvider(QObject *parent = nullptr);

    void setIsHeroLoading(bool newState);
    void setIsMetricsLoading(bool newState);
    void setIsAstronomyLoading(bool newState);
    void setIsTimelineLoading(bool newState);

    Q_INVOKABLE void fetchWeather(double latitude, double longitude);
    Q_INVOKABLE void updateWeather();

signals:
    void weatherFetched(const QJsonObject &json);

    void isHeroLoadingChanged();
    void isMetricsLoadingChanged();
    void isAstronomyLoadingChanged();
    void isTimelineLoadingChanged();

private slots:
    void onResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;

    double latitude;
    double longitude;

    bool isHeroLoading;
    bool isMetricsLoading;
    bool isAstronomyLoading;
    bool isTimelineLoading;

    QString fetchedAt;

    void updateFetchedAt();
};

#endif // WEATHERPROVIDER_H
