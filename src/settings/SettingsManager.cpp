#include "SettingsManager.h"
#include "DefaultSettings.h"

SettingsManager::SettingsManager(QObject *parent) : QObject(parent) {
    this->load();
}

void SettingsManager::load() {
    const int savedTemperatureUnit = settings.value("weather/units/temperature", static_cast<int>(DefaultSettings::TEMPERATURE_UNIT)).toInt();
    this->temperatureUnit = static_cast<TemperatureUnit>(savedTemperatureUnit);

    const int savedWindSpeedUnit = settings.value("weather/units/windSpeed", static_cast<int>(DefaultSettings::WIND_SPEED_UNIT)).toInt();
    this->windSpeedUnit = static_cast<WindSpeedUnit>(savedWindSpeedUnit);

    const int savedPrecipitationUnit = settings.value("weather/units/precipitation", static_cast<int>(DefaultSettings::PRECIPITATION_UNIT)).toInt();
    this->precipitationUnit = static_cast<PrecipitationUnit>(savedPrecipitationUnit);
}

TemperatureUnit SettingsManager::getTemperatureUnit() const {
    return this->temperatureUnit;
}

WindSpeedUnit SettingsManager::getWindSpeedUnit() const {
    return this->windSpeedUnit;
}

PrecipitationUnit SettingsManager::getPrecipitationUnit() const {
    return this->precipitationUnit;
}

void SettingsManager::setTemperatureUnit(TemperatureUnit newUnit) {
    if (this->temperatureUnit == newUnit) return;

    this->temperatureUnit = newUnit;
    this->settings.setValue("weather/units/temperature", static_cast<int>(newUnit));

    emit this->temperatureUnitChanged(newUnit);
}

void SettingsManager::setWindSpeedUnit(WindSpeedUnit newUnit) {
    if (this->windSpeedUnit == newUnit) return;

    this->windSpeedUnit = newUnit;
    this->settings.setValue("weather/units/windSpeed", static_cast<int>(newUnit));

    emit this->windSpeedUnitChanged(newUnit);
}

void SettingsManager::setPrecipitationUnit(PrecipitationUnit newUnit) {
    if (this->precipitationUnit == newUnit) return;

    this->precipitationUnit = newUnit;
    this->settings.setValue("weather/units/precipitation", static_cast<int>(newUnit));

    emit this->precipitationUnitChanged(newUnit);
}

void SettingsManager::resetToDefaults() {
    this->setTemperatureUnit(DefaultSettings::TEMPERATURE_UNIT);
    this->setWindSpeedUnit(DefaultSettings::WIND_SPEED_UNIT);
    this->setPrecipitationUnit(DefaultSettings::PRECIPITATION_UNIT);
}
