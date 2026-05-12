#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "src/network/WeatherProvider.h"
#include "src/network/LocationProvider.h"
#include "src/settings/SettingsManager.h"
#include "src/core/WeatherModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/icons/app/icon.ico"));
    app.setOrganizationName("iHexedCortexSoftware");
    app.setApplicationName("ThisDay");

    QQmlApplicationEngine engine;

    auto *weatherProvider = new WeatherProvider(&app);
    auto *locationProvider = new LocationProvider(&app);
    auto *settingsManager = new SettingsManager(&app);
    auto *weatherModel = new WeatherModel(weatherProvider, settingsManager, &app);

    engine.rootContext()->setContextProperty("weatherProvider", weatherProvider);
    engine.rootContext()->setContextProperty("locationProvider", locationProvider);
    engine.rootContext()->setContextProperty("settings", settingsManager);
    engine.rootContext()->setContextProperty("weatherModel", weatherModel);

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
