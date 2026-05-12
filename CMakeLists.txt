cmake_minimum_required(VERSION 3.16)

project(ThisDay VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appThisDay
    main.cpp

    resources.rc
)

qt_add_qml_module(appThisDay
    URI ThisDay
    VERSION 1.0

    QML_FILES
        Main.qml
        
        qml/components/Searchbar.qml
        qml/components/Sidebar.qml
        qml/components/SidebarButton.qml
        qml/components/SidebarStatItem.qml
        qml/components/WeatherCard.qml
        qml/components/Toolbar.qml

        qml/components/HourlyForecastItem.qml
        qml/components/HourlyForecastView.qml
        qml/components/DailyForecastItem.qml
        qml/components/WeatherDetailsItem.qml
        qml/components/WeatherDetailsCard.qml
        qml/components/ThemeSwitch.qml
        qml/components/DailyForecastView.qml
        qml/components/Shimmer.qml
        qml/components/SidebarToggle.qml
        qml/components/OverallWeatherSummaryCard.qml
        
        qml/pages/TodayPage.qml

        qml/shared/Theme.qml
        qml/shared/Directory.qml
        qml/shared/WeatherData.qml
        qml/shared/Clock.qml
        qml/shared/LocationData.qml

    RESOURCES
        resources/icons/app/icon.ico

        resources/images/background.jpg
        resources/images/title.png

        resources/icons/humidity-low.svg
        resources/icons/humidity-medium.svg
        resources/icons/humidity-high.svg
        resources/icons/max-temperature.png
        resources/icons/min-temperature.png

        resources/icons/toolbar/collapse.svg
        resources/icons/toolbar/expand.svg

        resources/icons/toolbar/searchbar/favorite.png
        resources/icons/toolbar/searchbar/not-favorite.png
        resources/icons/toolbar/searchbar/search.png

        resources/icons/sidebar/alerts.png
        resources/icons/sidebar/favorites.png
        resources/icons/sidebar/map.png
        resources/icons/sidebar/radar.png
        resources/icons/sidebar/reload.png
        resources/icons/sidebar/settings.png
        resources/icons/sidebar/today.png
        resources/icons/sidebar/forecast.png
        resources/icons/sidebar/sunrise.png
        resources/icons/sidebar/sunset.png

        resources/icons/weather/clear_sky_day.png
        resources/icons/weather/clear_sky_night.png
        resources/icons/weather/cloudy_day.png
        resources/icons/weather/cloudy_night.png
        resources/icons/weather/drizzle_day.png
        resources/icons/weather/drizzle_night.png
        resources/icons/weather/fog_day.png
        resources/icons/weather/fog_night.png
        resources/icons/weather/haze_day.png
        resources/icons/weather/haze_night.png
        resources/icons/weather/partly_cloudy_day.png
        resources/icons/weather/partly_cloudy_night.png
        resources/icons/weather/rain_day.png
        resources/icons/weather/rain_night.png
        resources/icons/weather/snow_day.png
        resources/icons/weather/snow_night.png
        resources/icons/weather/thunderstorm_day.png
        resources/icons/weather/thunderstorm_night.png
        resources/icons/weather/thunder_day.png
        resources/icons/weather/thunder_night.png

        resources/icons/weather/details/cloudiness.png
        resources/icons/weather/details/dew.png
        resources/icons/weather/details/humidity.png
        resources/icons/weather/details/precipitation.png
        resources/icons/weather/details/pressure.png
        resources/icons/weather/details/uv.png
        resources/icons/weather/details/visibility.png
        resources/icons/weather/details/wind.png

        resources/icons/theme/dark-theme.svg
        resources/icons/theme/light-theme.svg
        resources/icons/theme/auto-theme.svg

        qml/shared/qmldir
        
    SOURCES 
        src/network/WeatherProvider.h src/network/WeatherProvider.cpp
        src/network/LocationProvider.h src/network/LocationProvider.cpp
        src/settings/SettingsManager.h src/settings/SettingsManager.cpp
        src/settings/DefaultSettings.h
        src/common/types/WeatherUnits.h
        src/common/types/WeatherDataTypes.h
        src/utils/WeatherParser.h src/utils/WeatherParser.cpp
        src/core/WeatherModel.h src/core/WeatherModel.cpp
        src/common/types/WeatherModelTypes.h
        src/common/mappers/WeatherMapper.h
        src/common/mappers/WeatherMapper.cpp
        src/common/constants/WeatherStandardReferenceUnits.h
        src/utils/WeatherCalculator.h src/utils/WeatherCalculator.cpp
        src/common/types/SettingsTypes.h
        src/common/types/WeatherPresentationSettings.h
        src/common/mappers/WeatherSemanticMapper.h src/common/mappers/WeatherSemanticMapper.cpp
        src/utils/WeatherTimeUtils.h src/utils/WeatherTimeUtils.cpp
        src/common/mappers/WeatherEnumMapper.h src/common/mappers/WeatherEnumMapper.cpp
        src/common/formatters/WeatherFormatter.h src/common/formatters/WeatherFormatter.cpp
        src/common/formatters/WeatherDomainFormatter.h src/common/formatters/WeatherDomainFormatter.cpp
        SOURCES src/common/builders/WeatherSummaryBuilder.h src/common/builders/WeatherSummaryBuilder.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appThisDay PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appThisDay
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appThisDay
    PRIVATE Qt6::Quick
)
target_link_libraries(appThisDay PRIVATE Qt6::Core)
target_link_libraries(appThisDay PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appThisDay
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
