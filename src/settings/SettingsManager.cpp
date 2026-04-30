#include "SettingsManager.h"
#include "DefaultSettings.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent) {
    this->load();
}

void SettingsManager::load() {
    const int savedTemperatureUnit = settings.value("weather/temperatureUnit", static_cast<int>(DefaultSettings::TEMPERATURE_UNIT)).toInt();
    this->temperatureUnit = static_cast<WeatherTypes::TemperatureUnit>(savedTemperatureUnit);

    const int savedRefreshRate = settings.value("weather/refreshRate", static_cast<int>(DefaultSettings::REFRESH_RATE)).toInt();
    this->refreshRate = static_cast<WeatherTypes::RefreshRate>(savedRefreshRate);
}

WeatherTypes::TemperatureUnit SettingsManager::getTemperatureUnit() const {
    return this->temperatureUnit;
}

WeatherTypes::RefreshRate SettingsManager::getRefreshRate() const {
    return this->refreshRate;
}

void SettingsManager::setTemperatureUnit(WeatherTypes::TemperatureUnit newUnit) {
    if (this->temperatureUnit == newUnit) return;

    this->temperatureUnit = newUnit;
    this->settings.setValue("weather/temperatureUnit", static_cast<int>(newUnit));

    emit this->temperatureUnitChanged();
}

void SettingsManager::setRefreshRate(WeatherTypes::RefreshRate newRate) {
    if (this->refreshRate == newRate) return;

    this->refreshRate = newRate;
    this->settings.setValue("weather/refreshRate", static_cast<int>(newRate));

    emit this->refreshRateChanged();
}

void SettingsManager::resetToDefaults() {
    this->setTemperatureUnit(DefaultSettings::TEMPERATURE_UNIT);
    this->setRefreshRate(DefaultSettings::REFRESH_RATE);
}
