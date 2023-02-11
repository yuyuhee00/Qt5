import QtQuick

//Rectangle {
//    id: root
//    width: 200; height: 80
//    color: "linen"

//    TextInput {
//        id: input1
//        x: 8; y: 8
//        width: 96; height: 20
//        focus: true
//        text: "Text Input 1"
//        KeyNavigation.tab: input2
//    }

//    TextInput {
//        id: input2
//        x: 8; y:36
//        width: 96; height: 20
//        focus: true
//        text: "Text Input 2"
//        KeyNavigation.tab: input1
//    }
//}

import "./Ch04"

//Rectangle {
//    id: root
//    width: 200; height: 80
//    color: "linen"

//    TLineEditV1 {
//        id: input1
//        x: 8; y: 8
//        width: 96; height: 20

//        text: "Text Input 1"
//        KeyNavigation.tab: input2.input
//    }

//    TLineEditV1 {
//        id: input2
//        x: 8; y:36
//        width: 96; height: 20

//        text: "Text Input 2"
//        KeyNavigation.tab: input1.input
//    }
//}

//Rectangle {
//    id: root
//    width: 200; height: 80
//    color: "linen"

//    TLineEditV2 {
//        id: input1
//        x: 8; y: 8
//        width: 96; height: 20
//        text: "Text Input 1"
//        KeyNavigation.tab: input2.input
//    }

//    TLineEditV2 {
//        id: input2
//        x: 8; y:36
//        width: 96; height: 20

//        focus: true

//        text: "Text Input 2"
//        KeyNavigation.tab: input1.input
//    }
//}

//Rectangle {
//    id: root
//    width: 360; height: 120
//    color: "linen"

//    TTextEdit {
//        id: input
//        x: 8; y: 8
//        width: 120; height: 104
//        focus: true
//        text: "Text Edit"
//    }
//}


DarkSquare {
    id: root
    width: 400; height: 200

    GreenSquare {
        id: square
        x: 8; y: 8
        width: 30; height: 30
    }

    focus: true
    Keys.onLeftPressed: {
        if(parent.x+8 < square.x)
            square.x -= 8
    }
    Keys.onRightPressed: {
        if(parent.width-8 > square.x+square.width)
            square.x += 8
    }
    Keys.onUpPressed: {
        if(parent.y+8 < square.y)
            square.y -= 8
    }
    Keys.onDownPressed: {
    if(parent.height-8 > square.y+square.height)
        square.y += 8
    }

    Keys.onPressed: function(event) {
        switch(event.key) {
        case Qt.Key_Plus:
            square.scale += 0.2
            break;
        case Qt.Key_Minus:
            square.scale -= 0.2
            break
        case Qt.Key_Space:
            square.scale = 1.0
            break;
        }
    }
}
































