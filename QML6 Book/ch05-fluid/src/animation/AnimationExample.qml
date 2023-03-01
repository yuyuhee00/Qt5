import QtQuick

Image {
    id: root
    source: "assets/background.png"

    property int padding: 40
    property int duration: 4000
    property bool running: false

    property double opacity_down: 0.1
    property double scale_down: 0.1

    Image {
        id: box
        x: root.padding;
        y: (root.height-height)/2
        source: "assets/box_green.png"

        NumberAnimation on x {
            to: root.width - box.width - root.padding
            duration: root.duration
            running: root.running
        }
        RotationAnimation on rotation {
            to: 360
            duration: root.duration
            running: root.running
        }

        NumberAnimation on opacity {
            to: root.opacity - box.opacity - root.opacity_down
            duration: root.duration
            running: root.running
        }
        NumberAnimation on scale {
            to: root.scale - box.scale - root.scale_down
            duration: root.duration
            running: root.running
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.running = true
    }
}
