.pragma library

.import Weather.Types 1.0 as WeatherTypes

function temperature(value) {
    return value.toFixed(0);
}

function dewPoint(value) {
    return value.toFixed(1);
}
