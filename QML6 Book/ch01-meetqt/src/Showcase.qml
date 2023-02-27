import QtQuick

Image {
    id: root
    source: "images/background.png"

    property int blurRadius: 0

    Image {
        id: pole
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "images/pole.png"
    }

    Image {
        id: wheel
        anchors.centerIn: parent
        source: "images/pinwheel.png"
        Behavior on rotation {
            NumberAnimation {
                duration: 250
            }
        }

        onRotationChanged: {
            console.log("rotation: " + rotation)
        }
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            wheel.rotation += 90
        }
    }

    onWidthChanged: {
        console.log("Width: " + width)
    }
}
