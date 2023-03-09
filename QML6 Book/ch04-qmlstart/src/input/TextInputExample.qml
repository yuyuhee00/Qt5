import QtQuick

Rectangle {
    width: 200
    height: 80
    color: "linen"

    TextInput {
        id: input1
        x: 8; y: 8
        width: 96; height: 20
        focus: true
//        text: "Text Input 1-1"
//        inputMask: "999999"
        validator: RegularExpressionValidator {
            regularExpression: RegExp("[a-zA-Z0-9]+")
        }
    }

    TextInput {
        id: input2
        x: 8; y: 36
        width: 96; height: 20
        text: "Text Input 1-2"
    }
}
