import QtQuick

Rectangle {
    width: 140
    height: 120

//    Button {
    ButtonMinimalApiExample { // our Button component
        id: button
        x: 12; y: 12
        text: "Start"
//        color: "red"
        onClicked: {
            status.text = "Button clicked!"
        }
    }

    Text { // text changes when button was clicked
        id: status
        x: 12; y: 76
        width: 116; height: 26
        text: "waiting ..."
        horizontalAlignment: Text.AlignHCenter
    }
}
