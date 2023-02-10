import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    Image {
        id: qtlogo; anchors.centerIn: parent
        source: "./images/qtlogo.png"
    }

    SequentialAnimation {
        NumberAnimation {
            target: qtlogo; properties: "scale"
            from: 1.0; to: 0.5; duration: 1000
        }
        SequentialAnimation {
            NumberAnimation {
                target: qtlogo; properties: "rotation"
                from: 0.0; to: 360.0; duration: 1000
            }
            NumberAnimation {
                target: qtlogo; properties: "opacity"
                from: 1.0; to: 0.0; duration: 1000
            }
        }
        running: true
    }
}
