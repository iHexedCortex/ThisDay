import QtQuick 2.15
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    Text {
        id: overallSummaryInformationText
        anchors.fill: parent
        text: WeatherData.overallSummary
        font.pixelSize: window.width * 0.015
        font.weight: Font.DemiBold
        color: Theme.subTextColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
