#ifndef WEATHERCALCULATOR_H
#define WEATHERCALCULATOR_H

#include "../common/types/WeatherUnits.h"

class WeatherCalculator final
{

public:
    static double temperature(double value, TemperatureUnit targetUnit);
    static double windSpeed(double value, WindSpeedUnit targetUnit);
    static double precipitation(double value, PrecipitationUnit targetUnit);

private:
    static double temperatureToSRU(double value, TemperatureUnit fromUnit);
    static double temperatureFromSRU(double value, TemperatureUnit toUnit);

    static double windSpeedToSRU(double value, WindSpeedUnit fromUnit);
    static double windSpeedFromSRU(double value, WindSpeedUnit toUnit);

    static double precipitationToSRU(double value, PrecipitationUnit fromUnit);
    static double precipitationFromSRU(double value, PrecipitationUnit toUnit);
};

#endif // WEATHERCALCULATOR_H
