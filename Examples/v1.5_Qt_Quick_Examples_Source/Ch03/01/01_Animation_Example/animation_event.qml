import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 330; height: 230; visible: true

    Image {
        source: "images/qtlogo.png"
        x: 10; y: 20;
        id : logo

        NumberAnimation on scale
        {
            id : scaleAni
            from: 0.1; to: 1.0
            duration: 1000
            running: false
        }

        MouseArea {
            id: myMouse
            anchors.fill: parent;
            onClicked: {
                scaleAni.running = true
                console.log("running");
            }
        }
    }
}
