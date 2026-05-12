#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QObject>
#include <QJsonObject>

#include "../network/WeatherProvider.h"
#include "../common/types/WeatherModelTypes.h"
#include "../common/types/WeatherDataTypes.h"
#include "../utils/WeatherParser.h"
#include "../settings/SettingsManager.h"

class WeatherModel final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(WeatherHeroModel hero MEMBER hero NOTIFY heroModelChanged NOTIFY heroChanged)
    Q_PROPERTY(WeatherMetricsModel metrics MEMBER metrics NOTIFY metricsModelChanged NOTIFY metricsChanged)
    Q_PROPERTY(WeatherAstronomyModel astronomy MEMBER astronomy NOTIFY astronomyModelChanged NOTIFY astronomyChanged)
    Q_PROPERTY(WeatherTimelineModel timeline MEMBER timeline NOTIFY timelineModelChanged NOTIFY timelineChanged)
    Q_PROPERTY(QString summary MEMBER summary NOTIFY summaryChanged)

public:
    explicit WeatherModel(WeatherProvider *provider, SettingsManager *settings, QObject *parent = nullptr);

    WeatherProvider *provider;
    SettingsManager *settings;

    WeatherHeroData rawHero;
    WeatherMetricsData rawMetrics;
    WeatherAstronomyData rawAstronomy;
    WeatherTimelineData rawTimeline;

    WeatherHeroModel hero;
    WeatherMetricsModel metrics;
    WeatherAstronomyModel astronomy;
    WeatherTimelineModel timeline;
    QString summary;

private slots:
    void onWeatherFetched(const QJsonObject &json);

signals:
    void heroChanged();
    void metricsChanged();
    void astronomyChanged();
    void timelineChanged();
    void summaryChanged();
};

#endif // WEATHERMODEL_H
