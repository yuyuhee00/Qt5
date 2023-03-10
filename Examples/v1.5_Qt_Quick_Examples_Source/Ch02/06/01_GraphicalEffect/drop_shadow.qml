import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects

Window {
    visible: true; width: 300; height: 300
    Item {
        width: parent.width
        height: parent.height

        Image {
            width:300; height: 300
            id: butterfly
            source: "images/ball.png"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            visible: false
        }

        DropShadow {
            anchors.fill: butterfly
            radius: 8.0
            samples: 16
            horizontalOffset: 0
            verticalOffset: 20
            spread:0
            source: butterfly
            color: "#aa000000"
        }
    }
}
