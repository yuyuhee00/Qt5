import QtQuick

Rectangle {
    id: root
    width: 140
    height: 120

    property bool clicked: false

//    Button {
    ButtonMinimalApiExample { // our Button component
        id: button
        x: 12; y: 12
        text: "Start"
        back.color:  "red"
        back.border {
            width: 5
            color: "gray"
        }

        onClicked: function() {
//            status.text = "Button clicked!"
            root.clicked = !root.clicked
        }
    }

    Text {
        id: status
        x: 12; y: 76
        width: 116; height: 26
        text: root.clicked ? "Button clicked!" : "waiting ..."
        horizontalAlignment: Text.AlignHCenter
    }
}
