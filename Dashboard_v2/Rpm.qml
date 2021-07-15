import QtQuick 2.0

Item {
    id: id_root

    property int value: 0

    Rectangle {
        id: id_gear
		
		
		property int numberIndexs: 9
        property int startAngle: 234
        property int angleLength: 20
        property int maxSpeed: 8

        anchors.centerIn: parent
        height: Math.min(id_root.width, id_root.height)
        width: height
        radius: width/2
        color: "#000000"
        border.color: "white"
        border.width: id_gear.height * 0.02
		
		
	    Canvas {
            id:canvas
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            contextType: "2d"
            rotation: 100
            antialiasing: true
			
			onPaint: {
                var context = canvas.getContext('2d');
                context.strokeStyle = "blue";
                context.lineWidth = id_gear.height * 0.05 / 2;
                context.beginPath();
                context.arc(id_gear.height / 2, id_gear.height / 2, id_gear.height / 2 - id_gear.height * 0.05, 0.5, Math.PI * 1.1, false);
                context.stroke();

                context.strokeStyle = "red";
                context.lineWidth = id_gear.height * 0.05 / 2;
                context.beginPath();
                context.arc(id_gear.height / 2, id_gear.height / 2, id_gear.height / 2 - id_gear.height * 0.05, Math.PI * 1.1, Math.PI * 1.4, false);
                context.stroke();
            }
			
			
			}

			
			
			
			
        Repeater {
            model: id_gear.numberIndexs

            Item {
                height: id_gear.height/2
                transformOrigin: Item.Bottom
                rotation: index * id_gear.angleLength + id_gear.startAngle
                x: id_gear.width/2

                Rectangle {
                    height: id_gear.height * 0.05
                    width: height
                    color: "white"
                    antialiasing: true
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: id_gear.height * 0.05

                }
                /*
				Text {
                    anchors.centerIn: parent.horizontalCenter
                    x:0
                    y:id_gear.height*0.09
                    color: "white"
					rotation:360-(index * id_gear.angleLength + id_gear.startAngle)
                    text: index * (id_gear.maxSpeed / (id_gear.numberIndexs-1))
                    font.pixelSize: parent.height * 0.15
					font.family: "Comic Sans MS"
                }*/
					
            }
        }
    }
	
	
	Rectangle {
        id: id_center

        anchors.centerIn: parent
        height: id_gear.height*0.1
        width: height
        radius: width/2
        color: "white"
    }
	

    Text {
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: id_gear.verticalCenter
            topMargin: id_gear.height * 0.01
            rightMargin: id_gear.height
        }
        text: "RPM\n X1000"
        color: "white"
        font.pixelSize: id_gear.height * 0.1
        font.family: "Comic Sans MS"
    }
	
	SpeedNeedle {
        id: id_speedNeedle
        anchors {
            top: id_gear.top
            bottom: id_gear.bottom
            horizontalCenter: parent.horizontalCenter
        }
        value: id_root.value
        startAngle: id_gear.startAngle
        angleLength: id_gear.angleLength / (id_gear.maxSpeed / (id_gear.numberIndexs - 1))
    }
	
}
