import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects


Window {
    visible: true; width: 300; height: 300
    Item {
        width: parent.width
        height: parent.height

        Image {
            id: lenna
            source: "images/lenna.png"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true
            visible: false
        }

        Colorize {
            anchors.fill: lenna
            source: lenna
            hue: 0.8
            saturation: 1.0
            lightness: 0.2
        }
    }
}
