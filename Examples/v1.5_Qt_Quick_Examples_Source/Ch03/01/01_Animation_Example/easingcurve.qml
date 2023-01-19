import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    Image
    {
        id: easCur
        anchors.centerIn: parent
        source: "images/qtlogo.png"

        NumberAnimation {
            target: easCur; properties: "scale"
            from: 0.1; to: 1.0; duration: 1000
            easing.type: "OutExpo"
            running: true
        }
    }
}
