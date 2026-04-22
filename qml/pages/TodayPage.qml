import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../components"

Item {
    id: root

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: window.width * 0.015

        Toolbar {
            id: toolBar
            Layout.fillWidth: true
            Layout.preferredHeight: window.width * 0.03
            Layout.alignment: Qt.AlignTop
        }

        RowLayout {
            id: weatherInformationLayout
            Layout.fillWidth: true

            Item {
                Layout.fillWidth: true
            }

            WeatherCard {
                id: weatherCard
                Layout.preferredWidth: window.width * 0.35
                Layout.preferredHeight: Layout.preferredWidth * 0.75
                Layout.alignment: Qt.AlignVCenter
            }

            Item {
                Layout.fillWidth: true
            }

            Shimmer {
                id: weatherDetailsCardShimmer
                Layout.preferredWidth: weatherCard.width
                Layout.preferredHeight: weatherCard.height
                Layout.alignment: Qt.AlignVCenter
                loading: WeatherData.weatherDetailsDataLoading

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

        RowLayout {
            id: forecastLayout
            Layout.fillWidth: true

            Shimmer {
                id: hourlyForecastViewShimmer
                Layout.preferredWidth: root.width * 0.49
                Layout.preferredHeight: window.width * 0.14
                Layout.alignment: Qt.AlignHCenter
                loading: WeatherData.forecastDataLoading

                HourlyForecastView {
                    id: hourlyForecastView
                    anchors.fill: parent
                    visible: !hourlyForecastViewShimmer.loading
                }
            }

            Item {
                Layout.fillWidth: true
            }

            Shimmer {
                id: dailyForecastViewShimmer
                Layout.preferredWidth: hourlyForecastView.width
                Layout.preferredHeight: hourlyForecastView.height
                Layout.alignment: Qt.AlignLeft
                loading: WeatherData.forecastDataLoading

                DailyForecastView {
                    id: dailyForecastView
                    anchors.fill: parent
                    visible: !dailyForecastViewShimmer.loading
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
