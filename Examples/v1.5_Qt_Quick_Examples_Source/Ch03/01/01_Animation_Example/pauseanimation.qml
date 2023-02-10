import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    Image {
        id: logo
        anchors.centerIn: parent; source: "images/qtlogo.png"
    }

    SequentialAnimation {
        NumberAnimation {
            target: logo; properties: "scale"
            from: 0.0; to: 1.0; duration: 1000
        }
        PauseAnimation {
            duration: 1000
        }
        NumberAnimation {
            target: logo; properties: "scale"
            from: 1.0; to: 0.0; duration: 1000
        }
        running: true
    }
}
