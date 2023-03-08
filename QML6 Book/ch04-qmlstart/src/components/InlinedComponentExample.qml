import QtQuick

Rectangle {
    id: root
    width: 140
    height: 120

    property bool clicked: false

    // our inlined button ui
    Rectangle {
        id: button
        x: 12; y: 12
        width: 116; height: 26
        color: "lightsteelblue"
        border.color: "slategrey"
        Text {
            anchors.centerIn: parent
            text: "Start"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.clicked = !root.clicked
//                status.text = "Button clicked!"
            }
        }
    }

    // text changes when button was clicked
    Text {
        id: status
        x: 12; y: 76
        width: 116; height: 26
        text: root.clicked ? "Button clicked!" : "waiting ..."
        horizontalAlignment: Text.AlignHCenter
    }
}
