import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects


Window {
    visible: true; width: 300; height: 300

    Item {
        width: parent.width
        height: parent.height

        Image {
            id: bug
            source: "images/bug.jpg"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            visible: false
        }

        Desaturate {
            anchors.fill: bug
            source: bug
            desaturation: 1.0
        }
    }
}
