import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        spacing: 0

        ColumnLayout {
            id: locationLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            Shimmer {
                id: cityTextShimmer
                Layout.preferredWidth: root.width
                Layout.preferredHeight: Layout.preferredWidth * 0.15
                Layout.alignment: Qt.AlignHCenter
                loading: WeatherData.weatherDataLoading

                Text {
                    id: cityText
                    anchors.fill: parent
                    text: WeatherData.city
                    font.pixelSize: parent.height * 0.7
                    font.bold: true
                    color: Theme.textColor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible: !cityTextShimmer.loading
                }
            }

            Shimmer {
                id: dateTimeTextShimmer
                Layout.preferredWidth: root.width * 0.8
                Layout.preferredHeight: Layout.preferredWidth * 0.1
                Layout.alignment: Qt.AlignHCenter
                loading: WeatherData.weatherDataLoading

                Text {
                    id: dateTimeText
                    anchors.fill: parent
                    text: Clock.currentDate + " • " + Clock.currentTime
                    font.pixelSize: parent.height * 0.7
                    font.weight: Font.DemiBold
                    color: Theme.subTextColor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    visible: !dateTimeTextShimmer.loading
                }
            }
        }

        Shimmer {
            id: weatherIconAndInformationLayoutShimmer
            Layout.preferredWidth: root.width
            Layout.preferredHeight: root.height * 0.6
            loading: WeatherData.weatherDataLoading

            RowLayout {
                id: weatherIconAndInformationLayout
                anchors.fill: parent
                spacing: 0
                visible: !weatherIconAndInformationLayoutShimmer.loading

                Item {
                    Layout.fillWidth: true
                }

                Image {
                    id: weatherIconImage
                    Layout.preferredWidth: weatherIconAndInformationLayoutShimmer.width * 0.4
                    Layout.preferredHeight: Layout.preferredWidth
                    Layout.alignment: Qt.AlignVCenter
                    source: Directory.weatherIcons + WeatherData.condition + ".png"
                    fillMode: Image.PreserveAspectFit
                    visible: !weatherIconAndInformationLayoutShimmer.loading
                }

                Item {
                    Layout.fillWidth: true
                }

                ColumnLayout {
                    id: weatherInformationLayout
                    spacing: 0

                    Text {
                        id: temperatureText
                        Layout.preferredWidth: weatherIconAndInformationLayoutShimmer - weatherIconImage.width
                        Layout.preferredHeight: weatherIconAndInformationLayoutShimmer.height * 0.6
                        text: WeatherData.temperature + "°"
                        color: Theme.textColor
                        font.pixelSize: height * 0.8
                        font.bold: true
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        visible: !weatherIconAndInformationLayoutShimmer.loading
                    }

                    Text {
                        id: conditionText
                        Layout.preferredWidth: temperatureText.width
                        Layout.preferredHeight: temperatureText.height * 0.4
                        text: WeatherData.condition
                        color: Theme.subTextColor
                        font.pixelSize: height * 0.7
                        font.weight: Font.DemiBold
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        visible: !weatherIconAndInformationLayoutShimmer.loading
                    }

                    Item {
                        Layout.fillHeight: true
                    }
                }

                Item {
                    Layout.fillWidth: true
                }
            }
        }

        RowLayout {
            id: weatherExtraInformationLayout
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.1
            Layout.alignment: Qt.AlignHCenter
            spacing: 5

            Shimmer {
                id: maxTemperatureRectangleShimmer
                Layout.preferredWidth: root.width * 0.22
                Layout.preferredHeight: parent.height * 0.9
                radius: height * 0.5
                loading: WeatherData.forecastDataLoading

                Rectangle {
                    id: maxTemperatureRectangle
                    anchors.fill: parent
                    radius: parent.radius
                    color: Theme.badgeColor
                    visible: !maxTemperatureRectangleShimmer.loading

                    RowLayout {
                        id: maxTemperatureLayout
                        anchors.fill: parent
                        anchors.leftMargin: parent.width * 0.15
                        anchors.rightMargin: anchors.leftMargin
                        spacing: 0

                        Image {
                            id: maxTemperatureImage
                            source: "qrc:/qt/qml/ThisDay/resources/icons/max-temperature.png"
                            Layout.preferredWidth: parent.width * 0.35
                            Layout.preferredHeight: Layout.preferredWidth
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            id: maxTemperatureText
                            text: WeatherData.maxTemperature + "°"
                            color: Theme.textColor
                            font.pixelSize: parent.height * 0.6
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }

            Shimmer {
                id: minTemperatureRectangleShimmer
                Layout.preferredWidth: maxTemperatureRectangle.width
                Layout.preferredHeight: maxTemperatureRectangle.height
                radius: maxTemperatureRectangle.radius
                loading: WeatherData.forecastDataLoading

                Rectangle {
                    id: minTemperatureRectangle
                    anchors.fill: parent
                    radius: parent.radius
                    color: Theme.primaryColor
                    visible: !minTemperatureRectangleShimmer.loading

                    RowLayout {
                        id: minTemperatureLayout
                        anchors.fill: parent
                        anchors.leftMargin: maxTemperatureLayout.anchors.leftMargin
                        anchors.rightMargin: anchors.leftMargin
                        spacing: 0

                        Image {
                            id: minTemperatureImage
                            source: "qrc:/qt/qml/ThisDay/resources/icons/min-temperature.png"
                            Layout.preferredWidth: maxTemperatureImage.width
                            Layout.preferredHeight: maxTemperatureImage.height
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            id: minTemperatureText
                            text: WeatherData.minTemperature + "°"
                            color: Theme.textColor
                            font.pixelSize: maxTemperatureText.font.pixelSize
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }

            Shimmer {
                id: feelsLikeTemperatureRectangleShimmer
                Layout.preferredWidth: maxTemperatureRectangle.width * 2
                Layout.preferredHeight: maxTemperatureRectangle.height
                radius: maxTemperatureRectangle.radius
                loading: WeatherData.forecastDataLoading

                Rectangle {
                    id: feelsLikeTemperatureRectangle
                    anchors.fill: parent
                    radius: parent.radius
                    color: Theme.accentColor
                    visible: !feelsLikeTemperatureRectangleShimmer.loading

                    Text {
                        id: feelsLikeTemperatureText
                        anchors.centerIn: parent
                        text: "Feels Like " + WeatherData.feelsLike + "°"
                        color: Theme.textColor
                        font.pixelSize: maxTemperatureText.font.pixelSize
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }
    }
}
