import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    width: 200; height: 200
    visible: true

    Loader {
        anchors.centerIn: parent
        sourceComponent: rect
    }

    Component {
        id: rect
        Rectangle {
            width: 50; height: 50
            color: "red"
        }
    }
}
