#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>

#include "DefaultSettings.h"

class SettingsManager final : public QObject
{
    Q_OBJECT

    Q_PROPERTY(WeatherTypes::TemperatureUnit temperatureUnit READ getTemperatureUnit WRITE setTemperatureUnit NOTIFY temperatureUnitChanged)
    Q_PROPERTY(WeatherTypes::RefreshRate refreshRate READ getRefreshRate WRITE setRefreshRate NOTIFY refreshRateChanged)

public:
    explicit SettingsManager(QObject *parent = nullptr);

    WeatherTypes::TemperatureUnit getTemperatureUnit() const;
    WeatherTypes::RefreshRate getRefreshRate() const;

    void setTemperatureUnit(WeatherTypes::TemperatureUnit newUnit);
    void setRefreshRate(WeatherTypes::RefreshRate newRate);

    Q_INVOKABLE void resetToDefaults();

signals:
    void temperatureUnitChanged();
    void refreshRateChanged();

private:
    QSettings settings;
    WeatherTypes::TemperatureUnit temperatureUnit;
    WeatherTypes::RefreshRate refreshRate;

    void load();
};

#endif // SETTINGSMANAGER_H
