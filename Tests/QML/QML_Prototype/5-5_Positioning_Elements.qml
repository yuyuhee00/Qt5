import QtQuick
import "./Ch05"

//DarkSquare {
//    id: root
//    width: 120; height: 240

//    Column {
//        id: column
//        anchors.centerIn: parent
//        spacing: 8

//        RedSquare {}
//        GreenSquare { width: 96 }
//        BlueSquare {}
//    }
//}

//BrightSquare {
//    id: root
//    width: 400; height: 120

//    Row {
//        id: row
//        anchors.centerIn: parent
//        spacing: 8

//        RedSquare {}
//        GreenSquare {}
//        BlueSquare {}
//    }
//}

//BrightSquare {
//    id: root
//    width: 160; height: 160

//    Grid {
//        id: grid
//        rows: 2
//        columns: 2
//        anchors.centerIn: parent
//        spacing: 8

//        RedSquare {}
//        GreenSquare {}
//        BlueSquare {}
//        RedSquare {}
//    }
//}

//BrightSquare {
//    id: root
//    width: 160; height: 160

//    Flow {
//        id: flow
//        anchors.fill: parent
//        anchors.margins: 20
//        spacing: 20

//        RedSquare {}
//        GreenSquare {}
//        BlueSquare {}
//    }
//}

DarkSquare {
    id: root
    width: 252; height: 252

    property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]

    Grid {
        anchors.fill: parent
        anchors.margins: 8
        spacing: 4

        Repeater {
            model: 16
            delegate: Rectangle {
                required property int index
                property int colorIndex: Math.floor(Math.random()*3)
                width: 56; height: 56
                color: root.colorArray[colorIndex]
                border.color: Qt.lighter(color)

                Text {
                    anchors.centerIn: parent
                    color: "#f0f0f0"
                    text: "Cell " + parent.index
                }
            }
        }
    }
}
