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

        Item {
            Layout.fillHeight: true
        }

        Text {
            id: cityText
            Layout.fillWidth: true
            Layout.preferredHeight: width * 0.15
            Layout.alignment: Qt.AlignHCenter
            text: {
                if (LocationData.city !== LocationData.country)
                    return LocationData.city + ", " + LocationData.country;
                else
                    return LocationData.country;
            }
            font.pixelSize: height * 0.7
            font.bold: true
            color: Theme.textColor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: dateTimeText
            Layout.preferredWidth: parent.width * 0.8
            Layout.preferredHeight: width * 0.1
            Layout.alignment: Qt.AlignHCenter
            text: Clock.currentDate + " • " + Clock.currentTime
            font.pixelSize: height * 0.7
            font.weight: Font.DemiBold
            color: Theme.subTextColor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        RowLayout {
            id: weatherIconAndTemperatureLayout
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * 0.45
            spacing: 0

            Item {
                Layout.fillWidth: true
            }

            Image {
                id: weatherIconImage
                Layout.preferredWidth: parent.height
                Layout.preferredHeight: width
                Layout.alignment: Qt.AlignVCenter
                source: Directory.weatherIcons + weatherModel.hero.icon + ".png"
                fillMode: Image.PreserveAspectFit
            }

            Item {
                Layout.fillWidth: true
            }

            Text {
                id: temperatureText
                Layout.preferredWidth: weatherIconImage.width
                Layout.preferredHeight: weatherIconImage.height
                text: weatherModel.hero.temperature
                color: Theme.textColor
                font.pixelSize: height * 0.8
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Item {
                Layout.fillWidth: true
            }
        }

        Text {
            id: conditionText
            Layout.fillWidth: true
            Layout.preferredHeight: temperatureText.height * 0.35
            text: weatherModel.hero.condition
            color: Theme.subTextColor
            font.pixelSize: height * 0.6
            font.weight: Font.DemiBold
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Item {
            Layout.fillHeight: true
        }

        RowLayout {
            id: weatherSummaryLayout
            Layout.fillWidth: true
            Layout.preferredHeight: root.height * 0.1
            Layout.alignment: Qt.AlignHCenter
            spacing: 5

            Rectangle {
                id: maxTemperatureRectangle
                Layout.preferredWidth: root.width * 0.22
                Layout.preferredHeight: parent.height * 0.9
                radius: height * 0.5
                color: Theme.badgeColor

                RowLayout {
                    id: maxTemperatureLayout
                    anchors.fill: parent
                    anchors.leftMargin: parent.width * 0.15
                    anchors.rightMargin: anchors.leftMargin
                    spacing: 0

                    Image {
                        id: maxTemperatureImage
                        Layout.preferredWidth: parent.width * 0.35
                        Layout.preferredHeight: width
                        source: Directory.icons + "max-temperature.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    Text {
                        id: maxTemperatureText
                        text: weatherModel.hero.maxTemperature
                        color: Theme.weatherSummaryItemTextColor
                        font.pixelSize: parent.height * 0.7
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            Rectangle {
                id: minTemperatureRectangle
                Layout.preferredWidth: maxTemperatureRectangle.width
                Layout.preferredHeight: maxTemperatureRectangle.height
                radius: maxTemperatureRectangle.radius
                color: Theme.primaryColor

                RowLayout {
                    id: minTemperatureLayout
                    anchors.fill: parent
                    anchors.leftMargin: maxTemperatureLayout.anchors.leftMargin
                    anchors.rightMargin: anchors.leftMargin
                    spacing: 0

                    Image {
                        id: minTemperatureImage
                        Layout.preferredWidth: maxTemperatureImage.width
                        Layout.preferredHeight: maxTemperatureImage.height
                        source: Directory.icons + "min-temperature.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    Text {
                        id: minTemperatureText
                        text: weatherModel.hero.minTemperature
                        color: Theme.weatherSummaryItemTextColor
                        font.pixelSize: maxTemperatureText.font.pixelSize
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            Rectangle {
                id: feelsLikeTemperatureRectangle
                Layout.preferredWidth: maxTemperatureRectangle.width * 2
                Layout.preferredHeight: maxTemperatureRectangle.height
                radius: maxTemperatureRectangle.radius
                color: Theme.accentColor

                Text {
                    id: feelsLikeTemperatureText
                    anchors.centerIn: parent
                    text: "Feels like " + weatherModel.hero.feelsLikeTemperature
                    color: Theme.weatherSummaryItemTextColor
                    font.pixelSize: maxTemperatureText.font.pixelSize
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}
