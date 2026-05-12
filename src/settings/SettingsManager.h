#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>

#include "DefaultSettings.h"
#include "../common/types/WeatherUnits.h"

class SettingsManager final : public QObject
{
    Q_OBJECT

public:
    explicit SettingsManager(QObject *parent = nullptr);

    TemperatureUnit getTemperatureUnit() const;
    PrecipitationUnit getPrecipitationUnit() const;
    WindSpeedUnit getWindSpeedUnit() const;

    void setTemperatureUnit(TemperatureUnit unit);
    void setWindSpeedUnit(WindSpeedUnit unit);
    void setPrecipitationUnit(PrecipitationUnit unit);

    Q_INVOKABLE void resetToDefaults();

signals:
    void temperatureUnitChanged(TemperatureUnit unit);
    void windSpeedUnitChanged(WindSpeedUnit unit);
    void precipitationUnitChanged(PrecipitationUnit unit);

private:
    QSettings settings;

    TemperatureUnit temperatureUnit;
    WindSpeedUnit windSpeedUnit;
    PrecipitationUnit precipitationUnit;

    void load();
};

#endif // SETTINGSMANAGER_H
