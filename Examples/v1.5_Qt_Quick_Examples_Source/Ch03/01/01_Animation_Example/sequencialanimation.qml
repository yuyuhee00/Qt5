import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    Image {
        id: aniSeq
        anchors.centerIn: parent
        source: "images/qtlogo.png"
    }

    SequentialAnimation {
        NumberAnimation {
            target: aniSeq; properties: "scale"
            from: 1.0; to: 0.5; duration: 1000
        }
        NumberAnimation {
            target: aniSeq; properties: "opacity"
            from: 1.0; to: 0.5; duration: 1000
        }
        running: true
    }
}
