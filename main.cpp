#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "src/network/WeatherProvider.h"
#include "src/network/LocationProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/icons/app/icon.ico"));

    QQmlApplicationEngine engine;

    WeatherProvider weatherProvider;
    LocationProvider locationProvider;

    engine.rootContext()->setContextProperty("weatherProvider", &weatherProvider);
    engine.rootContext()->setContextProperty("locationProvider", &locationProvider);

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
