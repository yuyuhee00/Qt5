import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Window {
    visible: true; width: 300; height: 300

    Image {
        id: bug
        source: "images/butterfly.png"
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    ColorOverlay {
        anchors.fill: bug
        source: bug
        color: "#8000ff00"
    }
}
