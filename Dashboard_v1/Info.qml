import QtQuick 2.0

Item {
    id: id_root

    property var currentDate: new Date()
    property int fuelValue: 0

    Timer {
        id: timer
        repeat: true
        interval: 1000
        running: true

        onTriggered: id_root.currentDate = new Date()
    }

    Rectangle {
        id: id_info

        anchors.centerIn: parent
        height: Math.min(id_root.width, id_root.height)
        width: height
        radius: width/2
        color: "black"
        border.color: "white"
        border.width: id_info.height * 0.02
}}
