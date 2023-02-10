import QtQuick

//Item {
//    id: rectangleElement
//    width: 256; height: 128

//    Rectangle {
//        id: rect1
//        x: 12; y: 12
//        width: 76; height: 96
//        color: "lightsteelblue"
//    }
//    Rectangle {
//        id: rect2
//        x: 112; y: 12
//        width: 76; height: 96
//        border.color: "lightsteelblue"
//        border.width: 4
//        radius: 8
//    }

//    Rectangle {
//        id: rect3
//        x: 12; y: 120
//        width: 176; height: 96
//        border.color: "slategray"

//        gradient: Gradient {
//            GradientStop { position: 0.0; color: "lightsteelblue" }
//            GradientStop { position: 1.0; color: "slategray" }
//        }
//    }
//}

//Item {
//    id: textElement
//    width: 128; height: 64

//    Text {
//        text: "The quick brown fox"
//        elide: Text.ElideMiddle
//        style: Text.Sunken
//        styleColor: '#FF4444'
//        color: "#303030"
//        font {
//            family: "Ubuntu"
//            pixelSize: 10
//        }
//        verticalAlignment: Text.AlignTop
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//    }
//}

//Rectangle {
//    id: root
//    width: 120; height: 240
//    color: "#4A4A4A"

//    Image {
//        id: triangle
//        x: (parent.width - width)/2; y: 40
//        source:  'assets/ch04/triangle_red.png'
//    }
//    Text {
//        y: triangle.y + triangle.height + 20
//        width: root.width
//        color: 'white'
//        horizontalAlignment: Text.AlignHCenter
//        text: 'Triangle'
//    }
//}

//Text {
//    id: thisLabel
//    x: 24; y: 16
//    height: 2 * width
//    width: 100
//    property int times: 24
//    property alias anotherTimes: thisLabel.times
//    text: "Greetings " + times
//    font {
//        family: "Ubuntu"
//        pixelSize: (width - 24) / 10
//    }
//    KeyNavigation.tab: thisLabel
//    onHeightChanged: console.log('height: ', height)
//    focus: true
//    color: focus ? "red" : "black"
//}

Text {
    id: label
    x: 24; y: 24
    width: 240; height: 120
    property int spacePressses: 0
    text: "Space Pressed: " + spacePressses + " times"
    focus: true

    onTextChanged: function(text) {
        console.log("text changed to: ", text)
    }

    Keys.onSpacePressed: increase()
    Keys.onEscapePressed: label.text = ''

    function increase() {
        spacePressses = spacePressses + 1
    }
}
