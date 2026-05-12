#include "WeatherCalculator.h"

double WeatherCalculator::temperature(double value, TemperatureUnit targetUnit) {
    double normalizedTemperature = temperatureToSRU(value, targetUnit);
    return temperatureFromSRU(normalizedTemperature, targetUnit);
}

double WeatherCalculator::windSpeed(double value, WindSpeedUnit targetUnit) {
    double normalizedWindSpeed = windSpeedToSRU(value, targetUnit);
    return windSpeedFromSRU(normalizedWindSpeed, targetUnit);
}

double WeatherCalculator::precipitation(double value, PrecipitationUnit targetUnit) {
    double normalizedPrecipitation = precipitationToSRU(value, targetUnit);
    return precipitationFromSRU(normalizedPrecipitation, targetUnit);
}

double WeatherCalculator::temperatureToSRU(double value, TemperatureUnit fromUnit) {
    switch(fromUnit) {
        case TemperatureUnit::Celsius: return value;
        case TemperatureUnit::Fahrenheit: return (value - 32.0) * 5.0 / 9.0;
        default: return value;
    }
}

double WeatherCalculator::temperatureFromSRU(double value, TemperatureUnit toUnit) {
    switch(toUnit) {
        case TemperatureUnit::Celsius: return value;
        case TemperatureUnit::Fahrenheit: return value * 9.0 / 5.0 + 32.0;
        default: return value;
    }
}

double WeatherCalculator::windSpeedToSRU(double value, WindSpeedUnit fromUnit) {
    switch(fromUnit) {
        case WindSpeedUnit::MS: return value;
        case WindSpeedUnit::KMH: return value / 3.6;
        case WindSpeedUnit::MPH: return value * 0.44704;
        default: return value;
    }
}

double WeatherCalculator::windSpeedFromSRU(double value, WindSpeedUnit toUnit) {
    switch(toUnit) {
        case WindSpeedUnit::MS: return value;
        case WindSpeedUnit::KMH: return value * 3.6;
        case WindSpeedUnit::MPH: return value / 0.44704;
        default: return value;
    }
}

double WeatherCalculator::precipitationToSRU(double value, PrecipitationUnit fromUnit) {
    switch(fromUnit) {
        case PrecipitationUnit::MM: return value;
        case PrecipitationUnit::IN: return value * 25.4;
        default: return value;
    }
}

double WeatherCalculator::precipitationFromSRU(double value, PrecipitationUnit toUnit) {
    switch(toUnit) {
        case PrecipitationUnit::MM: return value;
        case PrecipitationUnit::IN: return value / 25.4;
        default: return value;
    }
}
