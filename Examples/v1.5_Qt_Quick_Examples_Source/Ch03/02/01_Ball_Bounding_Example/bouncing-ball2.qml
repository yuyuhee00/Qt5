import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 600; height: 300; visible: true

    Image {
        source: "images/ball.png"
        anchors.horizontalCenter: parent.horizontalCenter

        SequentialAnimation on y {
            NumberAnimation {
                from: 200; to: 20
                easing.type: "OutQuad"
                duration: 250
            }
            NumberAnimation {
                from: 20; to: 200
                easing.type: "OutBounce"
                duration: 1000
            }
        }
    }
}
