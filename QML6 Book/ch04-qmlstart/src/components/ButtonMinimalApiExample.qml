import QtQuick

Item {
    id: root
    width: 116; height: 26

    // export button properties
    property alias text: label.text
    property alias back: recta
    signal clicked

    Rectangle {
        id: recta
        anchors.fill: parent
        color: "lightsteelblue"
        border.color: "slategrey"
    }

    Text {
        id: label
        anchors.centerIn: parent
        text: "Start"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
