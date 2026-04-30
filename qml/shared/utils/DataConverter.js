.pragma library

.import Weather.Types 1.0 as WeatherTypes

function temperature(celsius, unit) {
    if (unit === WeatherTypes.WeatherTypes.TemperatureUnit.Fahrenheit) {
        return (celsius * 9/5) + 32;
    }
    return celsius;
}
