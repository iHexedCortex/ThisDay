pragma Singleton
import QtQuick 2.15

QtObject {
    id: root

    property string currentTime: "--:--"
    property string currentDate: "--"

    property var _timer: Timer {
        interval: 1000
        running: true
        repeat: true
        triggeredOnStart: true

        onTriggered: {
            const now = new Date();
            root.currentTime = now.toLocaleTimeString(Qt.locale(), "HH:mm");
            root.currentDate = now.toLocaleDateString(Qt.locale(), "dddd, MMMM d");
        }
    }
}
