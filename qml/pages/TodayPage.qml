import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"
import "../components"

Item {
    id: root

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 15

        Toolbar {
            id: toolBar
            Layout.fillWidth: true
            Layout.preferredHeight: root.width * 0.04
            Layout.minimumHeight: 30
            Layout.alignment: Qt.AlignTop
        }

        Flickable {
            id: flickable
            Layout.fillWidth: true
            Layout.fillHeight: true
            contentHeight: mainContentLayout.implicitHeight
            clip: true
            interactive: true

            ColumnLayout {
                id: mainContentLayout
                width: parent.width
                spacing: mainLayout.spacing

                GridLayout {
                    id: weatherInformationLayout
                    Layout.fillWidth: true
                    columns: window.width >= 1000 ? maxColumns : minColumns
                    rowSpacing: mainLayout.spacing

                    readonly property int maxColumns: 6
                    readonly property int minColumns: 3
                    readonly property bool isWrapped: columns === minColumns

                    Item {
                        Layout.fillWidth: true
                    }

                    Shimmer {
                        id: weatherCardShimmer
                        Layout.preferredWidth: parent.isWrapped ? root.width * 0.9 : root.width * 0.43
                        Layout.preferredHeight: Layout.preferredWidth * 0.8
                        Layout.alignment: Qt.AlignVCenter
                        loading: weatherProvider.isHeroLoading

                        WeatherCard {
                            id: weatherCard
                            anchors.fill: parent
                            visible: !weatherCardShimmer.loading
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                    Shimmer {
                        id: weatherDetailsCardShimmer
                        Layout.preferredWidth: weatherCard.width
                        Layout.preferredHeight: weatherCard.height
                        Layout.alignment: Qt.AlignVCenter
                        loading: weatherProvider.isMetricsLoading

                        WeatherDetailsCard {
                            id: weatherDetailsCard
                            anchors.fill: parent
                            visible: !weatherDetailsCardShimmer.loading
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }

                GridLayout {
                    id: forecastLayout
                    Layout.fillWidth: true
                    columns: weatherInformationLayout.columns

                    Item {
                        Layout.fillWidth: true
                    }

                    Shimmer {
                        id: hourlyForecastViewShimmer
                        Layout.preferredWidth: weatherInformationLayout.isWrapped ? root.width * 0.92 : root.width * 0.48
                        Layout.preferredHeight: root.height * 0.28
                        Layout.alignment: Qt.AlignHCenter
                        radius: height * 0.1
                        loading: weatherProvider.isTimelineLoading

                        HourlyForecastView {
                            id: hourlyForecastView
                            anchors.fill: parent
                            radius: hourlyForecastViewShimmer.radius
                            visible: !hourlyForecastViewShimmer.loading
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                    Item {
                        Layout.fillWidth: true
                    }

                    Shimmer {
                        id: dailyForecastViewShimmer
                        Layout.preferredWidth: hourlyForecastView.width
                        Layout.preferredHeight: hourlyForecastView.height
                        Layout.alignment: Qt.AlignLeft
                        radius: hourlyForecastViewShimmer.radius
                        loading: weatherProvider.isTimelineLoading

                        DailyForecastView {
                            id: dailyForecastView
                            anchors.fill: parent
                            radius: dailyForecastViewShimmer.radius
                            visible: !dailyForecastViewShimmer.loading
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }

                Shimmer {
                    id: overallWeatherSummaryCardShimmer
                    Layout.fillWidth: true
                    Layout.preferredHeight: root.width * 0.05
                    Layout.alignment: Qt.AlignHCenter
                    loading: weatherProvider.isHeroLoading

                    OverallWeatherSummaryCard {
                        id: overallWeatherSummaryCard
                        anchors.fill: parent
                        radius: parent.radius
                        visible: !overallWeatherSummaryCardShimmer.loading
                    }
                }
            }
        }
    }
}
