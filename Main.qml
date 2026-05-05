import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "qml/components"
import "qml/pages"
import "qml/shared"
import Weather.Types 1.0

Window {
    id: window
    width: 800
    height: 500
    visible: true
    title: "ThisDay Weather"
    color: Theme.backgroundColor

    property bool sidebarExpanded: true
    property int currentPageIndex: 0

    RowLayout {
        id: mainLayout
        anchors.fill: parent

        Sidebar {
            id: sidebar
            Layout.preferredWidth: window.sidebarExpanded ? window.width * 0.17 : window.width * 0.055
            Layout.fillHeight: true
            expanded: window.sidebarExpanded
        }

        Rectangle {
            id: pageDisplayRectangle
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: window.width * 0.008
            color: "transparent"

            StackLayout {
                id: stackLayout
                anchors.fill: parent
                currentIndex: window.currentPageIndex

                TodayPage {
                    id: todayPage
                }
            }
        }
    }

    Component.onCompleted: locationProvider.detectCity()

    Connections {
        target: locationProvider

        function onCityDetected(currentCity) {
            locationProvider.searchCity(currentCity);
        }

        function onCoordinatesFound(latitude, longitude) {
            weatherProvider.fetchWeather(latitude, longitude);
        }
    }
}
