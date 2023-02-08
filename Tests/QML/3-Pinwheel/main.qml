import QtQuick 2.9

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property int rotationStep: 250

    Image {
        id: background
        width: parent.width
        height: parent.height
        source: "qrc:/images/background.png"
    }

    Image {
        id: pole
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "qrc:/images/pole.png"
    }

    Image {
        id: wheel
        anchors.centerIn: parent
        source: "qrc:/images/pinwheel.png"

        Behavior on rotation {
            NumberAnimation {
                duration : 250
            }
        }
        MouseArea {
            anchors.fill: parent
            onPressed: {
                wheel.rotation += 90
            }
        }
    }

    Item {
        anchors.fill: parent
        focus: true
        Keys.onLeftPressed: {
            console.log("move left")
            wheel.rotation -= root.rotationStep
        }
        Keys.onRightPressed: {
            console.log("move right")
            wheel.rotation += root.rotationStep
        }
    }
}

