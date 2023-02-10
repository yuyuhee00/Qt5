import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    Image {
        id: aniPara
        anchors.centerIn: parent
        source: "images/qtlogo.png"
    }

    ParallelAnimation {
        NumberAnimation {
            target: aniPara; properties: "scale"
            from: 1.0; to: 0.5; duration: 1000
        }
        NumberAnimation {
            target: aniPara; properties: "opacity"
            from: 1.0; to: 0.5; duration: 1000
        }
        running: true
    }
}
