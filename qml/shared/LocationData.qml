pragma Singleton
import QtQuick 2.15

QtObject {
    property real latitude: locationProvider.latitude
    property real longitude: locationProvider.longitude
    property string city: locationProvider.city
    property string country: locationProvider.country
}
