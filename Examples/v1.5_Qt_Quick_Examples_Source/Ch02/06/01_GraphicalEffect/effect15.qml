import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

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
