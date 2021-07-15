import QtQuick 2.0

Item {
    id: id_dashboard

    property int count: 0
    property int randNum: 0
    width: 450
    Timer{
        id: id_timer
        repeat: true
        interval: 1000
        running: true

        onTriggered: {
                if(id_speed.value == 280) id_speed.value=280;
                else id_speed.value=id_speed.value+10;

            if(count % 2 == 0){
                id_turnLeft.isActive = true
                id_turnRight.isActive = false
            }else{
                id_turnLeft.isActive = false
                id_turnRight.isActive = true
            }
            count++
        }
    }

    Rectangle {
        id: id_speedArea

        anchors {
            horizontalCenter: parent.horizontalCenter
        }
        width: parent.width * 0.4
        height: width
        color: "black"
        radius: width/2
        z: 1

        Speed {
            id: id_speed
            anchors.fill: id_speedArea
            anchors.margins: id_speedArea.width * 0.025
        }
    }


    Rectangle {
        anchors {
            bottom: id_speedArea.bottom
            left: id_speedArea.horizontalCenter
            right: id_speedArea.horizontalCenter
        }
        height: id_speedArea.width / 2
        color: "black"
        z: -1
    }

    Turn {
        id: id_turnLeft

        anchors {
            right: id_speedArea.left
            rightMargin: id_speedArea.height * 0.04
            bottom: id_speedArea.bottom
            bottomMargin: id_speedArea.height * 0.01
        }
        width: id_speedArea.width / 5.5
        height: id_speedArea.height / 8.2

        isActive: false
    }

    Turn {
        id: id_turnRight

        anchors {
            left: id_speedArea.right
            leftMargin: id_speedArea.height * 0.04
            bottom: id_speedArea.bottom
            bottomMargin: id_speedArea.height * 0.01
        }
        width: id_speedArea.width / 5.5
        height: id_speedArea.height / 8.2
        transformOrigin: Item.Center
        rotation: 180

        isActive: true
    }
}
