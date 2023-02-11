import QtQuick

Image {
    id: root
    source: "assets/ch05/background.png"

    property int padding: 40
    property int duration: 4000
    property bool running: false

    Image {
        id: box
        x: root.padding; y: (root.height-height)/2
        source: "assets/ch05/box_green.png"


        NumberAnimation on x{
            to: root.width-box.width-root.padding
            duration: root.duration
            running: root.running
            easing.type: Easing.InOutQuad
        }
        RotationAnimation on rotation {
            to: 360
            duration: root.duration
            running: root.running
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.running = true
    }
}
