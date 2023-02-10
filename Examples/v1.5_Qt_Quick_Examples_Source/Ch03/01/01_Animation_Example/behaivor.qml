import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 330; height: 230; visible: true

    Rectangle {
        width: 330; height: 230;
        id: rect
        color: "red"

        Behavior on width {
            NumberAnimation { duration: 1000 }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: rect.width = 50
        }
    }
}
