import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Window {
    visible: true; width: 300; height: 300
    Item {
        width: parent.width
        height: parent.height

        Image {
            id: lenna; source: "images/lenna.png"
            sourceSize: Qt.size(parent.width, parent.height)
            smooth: true; visible: false
        }
        HueSaturation {
            anchors.fill: lenna; source: lenna
            hue: 0.3
            saturation: 0
            lightness: 0
        }
    }
}
