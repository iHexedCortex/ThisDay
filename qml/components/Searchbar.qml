import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../shared"

Rectangle {
    id: root
    height: width * 0.09
    color: Theme.surfaceColor
    radius: height * 0.5
    border.width: 1
    border.color: Theme.cardBorderColor

    property bool isFavorite: false

    RowLayout {
        id: mainLayout
        anchors.fill: root
        anchors.leftMargin: width * 0.04
        anchors.rightMargin: anchors.leftMargin
        spacing: 10

        Image {
            id: searchImage
            source: Directory.searchbarIcons + "search.png"
            Layout.preferredWidth: mainLayout.height * 0.6
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignVCenter
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: searchImage
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    searchTextField.accepted();
                }
            }
        }

        TextField {
            id: searchTextField
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignVCenter
            placeholderText: "Search for a city or zip code..."
            placeholderTextColor: Theme.subTextColor
            background: null
            color: Theme.textColor
            font.pixelSize: root.height * 0.4
            verticalAlignment: TextInput.AlignVCenter

            onTextChanged: {
                font.bold = text.length > 0;
            }

            onAccepted: {
                weatherProvider.fetchWeather(text);
            }
        }

        Image {
            id: favoriteImage
            source: root.isFavorite ? Directory.searchbarIcons + "favorite.png" : Directory.searchbarIcons + "not-favorite.png"
            Layout.preferredWidth: searchImage.width
            Layout.preferredHeight: Layout.preferredWidth
            Layout.alignment: Qt.AlignVCenter
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: favoriteImage
                cursorShape: Qt.PointingHandCursor
                onClicked: root.isFavorite = !root.isFavorite
            }
        }
    }
}
