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

        GaussianBlur {
            anchors.fill: lenna
            source: lenna
            deviation: 4
            radius: 8
            samples: 16
        }
    }
}
