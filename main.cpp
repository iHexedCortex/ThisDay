#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "src/network/WeatherProvider.h"
#include "src/network/LocationProvider.h"
#include "src/settings/SettingsManager.h"
#include "src/common/types/WeatherTypes.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/icons/app/icon.ico"));

    QQmlApplicationEngine engine;

    auto* weatherProvider = new WeatherProvider(&app);
    auto* locationProvider = new LocationProvider(&app);
    auto* settingsManager = new SettingsManager(&app);

    engine.rootContext()->setContextProperty("weatherProvider", weatherProvider);
    engine.rootContext()->setContextProperty("locationProvider", locationProvider);
    engine.rootContext()->setContextProperty("settings", settingsManager);

    qRegisterMetaType<HourlyForecastUnit>("HourlyForecastUnit");
    qRegisterMetaType<DailyForecastUnit>("DailyForecastUnit");
    qRegisterMetaType<HourlyForecastModel>("HourlyForecastModel");
    qRegisterMetaType<DailyForecastModel>("DailyForecastModel");

    qmlRegisterUncreatableMetaObject(
        WeatherTypes::staticMetaObject,
        "Weather.Types",
        1, 0,
        "WeatherTypes",
        "Error: Weather is a namespace"
    );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );

    engine.loadFromModule("ThisDay", "Main");

    return app.exec();
}
