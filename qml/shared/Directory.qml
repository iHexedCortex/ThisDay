pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property url resources: "qrc:/qt/qml/ThisDay/resources/"
    readonly property url icons: resources + "icons/"
    readonly property url images: resources + "images/"
    readonly property url appIcons: icons + "app/"
    readonly property url themeIcons: icons + "theme/"
    readonly property url weatherIcons: icons + "weather/"
    readonly property url weatherDetailsIcons: weatherIcons + "details/"
    readonly property url sidebarIcons: icons + "sidebar/"
    readonly property url toolbarIcons: icons + "toolbar/"
    readonly property url searchbarIcons: toolbarIcons + "searchbar/"
}
