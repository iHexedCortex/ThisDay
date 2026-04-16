pragma Singleton
import QtQuick 2.15

QtObject {
    property bool isDark: true

    function theme(lightColor, darkColor) {
        return isDark ? darkColor : lightColor ;
    }

    readonly property color backgroundColor: theme("#F3F4F6", "#0B0E14")
    readonly property color surfaceColor: theme("#FFFFFF", "#151921")
    readonly property color primaryColor: theme("#4FACFE", "#4FACFE")
    readonly property color accentColor: theme("#FF9500", "#FFA62D")
    readonly property color textColor: theme("#1F2937", "#E4E7EB")
    readonly property color subTextColor: theme("#6B7280", "#9BA3AF")
    readonly property color cardBorderColor: theme("#E5E7EB", "#2D343F")
    readonly property color badgeColor: theme("#EF4444", "#FF0000")
    readonly property color shimmerBaseColor: theme("#E0E0E0", "#232634")
    readonly property color shimmerHighlightColor: theme("#F5F5F5", "#30FFFFFF")
}
