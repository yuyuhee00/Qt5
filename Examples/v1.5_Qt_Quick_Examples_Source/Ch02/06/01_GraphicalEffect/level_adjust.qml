import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects


Window {
    visible: true; width: 300; height: 300
    Item {
        width: parent.width
        height: parent.height

        Image {
            id: butterfly; source: "images/butterfly.png"
            sourceSize: Qt.size(parent.width/2, parent.height/2)
            smooth: true; visible: false
        }

        Image {
            id: butterfly2; source: "images/butterfly.png"
            anchors.left: butterfly.right
            sourceSize: Qt.size(parent.width/2, parent.height/2)
            smooth: true; visible: true
        }

        LevelAdjust {
            anchors.fill: butterfly
            source: butterfly
            minimumInput: "#00000070"
            maximumInput: "#ffffff"
//            minimumOutput: "#000000"
//            maximumOutput: "#ffffff"
            minimumOutput: "#00ffffff"
            maximumOutput: "#ff000000"
        }
    }
}
