import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects

Window {
    visible: true; width: 300; height: 300

    Rectangle {
        anchors.fill: parent
        color: "black"
    }

    Image {
        id: butterfly
        source: "images/ball.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    Glow {
        anchors.fill: butterfly
        radius: 30
        samples: 16
        color: "green"
        source: butterfly
    }
}
