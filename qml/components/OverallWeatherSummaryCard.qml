import QtQuick 2.15
import "../shared"

Rectangle {
    id: root
    color: "transparent"

    Text {
        id: overallSummaryInformationText
        anchors.fill: parent
        text: weatherModel.summary
        font.pixelSize: parent.width * 0.02
        font.weight: Font.DemiBold
        color: Theme.subTextColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
