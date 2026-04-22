import QtQuick 2.15
import QtQuick.Shapes 1.15
import "../shared"

Rectangle {
    id: root
    color: loading ? Theme.shimmerBaseColor : "transparent"
    radius: height * 0.07
    clip: loading

    required property bool loading

    Rectangle {
        id: shimmer
        width: parent.width * 2
        height: parent.height
        radius: parent.radius
        clip: true
        y: 0
        x: -parent.width

        visible: root.loading

        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: 0.0; color: "transparent" }
            GradientStop { position: 0.4; color: "transparent" }
            GradientStop {position: 0.5; color: Theme.shimmerHighlightColor}
            GradientStop { position: 0.6; color: "transparent" }
            GradientStop { position: 1.0; color: "transparent" }
        }

        PropertyAnimation on x {
            from: -root.width * 1.5
            to: root.width * 1.5
            duration: 1200
            loops: Animation.Infinite
            running: root.loading
        }
    }
}
