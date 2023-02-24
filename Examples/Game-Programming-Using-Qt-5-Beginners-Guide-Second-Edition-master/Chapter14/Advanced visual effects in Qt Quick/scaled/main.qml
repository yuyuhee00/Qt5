import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    UI {
        id: ui

        anchors.centerIn: parent
        scale: Math.min(parent.width / width,
                        parent.height / height)
    }
}
