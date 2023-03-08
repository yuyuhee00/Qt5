import QtQuick

Rectangle {
    width: 240
    height: 120

    Text {
        id: label

        x: 24; y: 24

        // custom counter property for space presses
        property int spacePresses: 0

        text: "Space pressed: " + spacePresses + " times"

//        onTextChanged: {
//            console.log("text changed to:", text)
//        }

        //
        // (1) handler for text changes. Need to use function to capture parameters
        //
//        onTextChanged: function(text) {
//            console.log("text changed to:", text)
//        }
        onTextChanged: (text) => {
            console.log("text changed to:", text)
        }


        // need focus to receive key events
        focus: true

        Keys.onSpacePressed: {
            increment()
        }

        Keys.onEscapePressed: {
//             spacePresses = 0
            label.text = ''

        }

        function increment() {
            spacePresses = spacePresses + 1
        }
    }
}
