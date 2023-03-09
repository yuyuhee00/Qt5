import QtQuick

Rectangle {
    width: 200
    height: 180
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
        KeyNavigation.tab : input2
    }

    TextInput {
        id: input2
        x: 8; y: 36
        width: 96; height: 20
        text: "Text Input 1-2"

        KeyNavigation.tab : input3
    }

    FocusScope {
         x: 8; y:86
         width: 96; height: 80
        Rectangle {
           anchors.fill: parent
            color: "lightgray"
        }

        TextInput {
            id: input3
            anchors.fill: parent
//            text: "Text Input 1-3"
            focus: true
            clip: true
            wrapMode: TextInput.WrapAnywhere
            validator: RegularExpressionValidator {
                regularExpression: RegExp("[a-zA-Z0-9]+")
            }
            KeyNavigation.tab : input1
        }
    }
}
