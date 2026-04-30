import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: Theme.surfaceColor

    property int activeTabIndex: 0
    property bool expanded: true

    Rectangle {
        id: rightBorderRectangle
        anchors.left: parent.right
        width: 1
        height: parent.height
        color: Theme.cardBorderColor
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: parent.height * 0.006

        Item {
            Layout.fillHeight: true
            visible: root.expanded
        }

        Image {
            id: appTitleImage
            Layout.fillWidth: true
            Layout.preferredHeight: root.width * 0.3
            source: Directory.images + "title.png"
            fillMode: Image.PreserveAspectFit
            visible: root.expanded
        }

        Item {
            Layout.fillHeight: true
            visible: root.expanded
        }

        ColumnLayout {
            id: buttonContainerLayout
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: root.expanded ? 0 : root.height * 0.01

            SidebarButton {
                id: todayButton
                Layout.preferredWidth: root.expanded ? root.width * 0.9 : root.width * 0.8
                Layout.preferredHeight: root.expanded ? Layout.preferredWidth * 0.2 : Layout.preferredWidth
                icon: Directory.sidebarIcons + "today.png"
                label: "Today"
                isActive: root.activeTabIndex === 0
                onClicked: root.activeTabIndex = 0
                iconOnly: !root.expanded
            }

            SidebarButton {
                id: forecastButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "forecast.png"
                label: "Forecast"
                isActive: root.activeTabIndex === 1
                onClicked: root.activeTabIndex = 1
                iconOnly: !root.expanded
            }

            SidebarButton {
                id: mapsButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "map.png"
                label: "Maps"
                isActive: root.activeTabIndex === 2
                onClicked: root.activeTabIndex = 2
                iconOnly: !root.expanded
            }

            SidebarButton {
                id: radarButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "radar.png"
                label: "Radar"
                isActive: root.activeTabIndex === 3
                onClicked: root.activeTabIndex = 3
                iconOnly: !root.expanded
            }

            SidebarButton {
                id: alertsButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "alerts.png"
                label: "Alerts"
                isActive: root.activeTabIndex === 4
                onClicked: root.activeTabIndex = 4
                iconOnly: !root.expanded
                badgeCount: 3
            }

            SidebarButton {
                id: favoritesButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "favorites.png"
                label: "Favorites"
                isActive: root.activeTabIndex === 5
                onClicked: root.activeTabIndex = 5
                iconOnly: !root.expanded
            }

            SidebarButton {
                id: settingsButton
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height
                icon: Directory.sidebarIcons + "settings.png"
                label: "Settings"
                isActive: root.activeTabIndex === 6
                onClicked: root.activeTabIndex = 6
                iconOnly: !root.expanded
            }
        }

        Item {
            Layout.fillHeight: true
        }

        ColumnLayout {
            id: sidebarStatContainerLayout
            Layout.fillWidth: true

            SidebarStatItem {
                id: sunriseStatItem
                Layout.preferredWidth: todayButton.width
                Layout.preferredHeight: todayButton.height * 1.5
                icon: Directory.sidebarIcons + "sunrise.png"
                label: "Sunrise"
                value: WeatherData.sunrise
                visible: root.expanded
            }

            SidebarStatItem {
                id: sunsetStatItem
                Layout.preferredWidth: sunriseStatItem.width
                Layout.preferredHeight: sunriseStatItem.height
                icon: Directory.sidebarIcons + "sunset.png"
                label: "Sunset"
                value: WeatherData.sunset
                visible: root.expanded
            }
        }

        Item {
            Layout.preferredHeight: root.height * 0.05
        }

        SidebarStatItem {
            id: updateStatItem
            Layout.preferredWidth: sunriseStatItem.width
            Layout.preferredHeight: sunriseStatItem.height
            icon: Directory.sidebarIcons + "reload.png"
            label: "Last updated"
            value: "Today" + " • " + WeatherData.lastUpdatedTime
            rotatableImage: true
            visible: root.expanded

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: weatherProvider.updateWeather()
            }
        }
    }

    onActiveTabIndexChanged: window.currentPageIndex = root.activeTabIndex
}
