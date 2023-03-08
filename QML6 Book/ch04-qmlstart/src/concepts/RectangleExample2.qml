import QtQuick

Item {
    width: 200
    height: 120

    Rectangle {
        id: rect1
        x: 12; y: 12
        width: 76; height: 96
        color: "lightsteelblue"
    }
    Rectangle {
        id: rect2
        x: 112; y: 12
        width: 76; height: 96

//        // SVG
//        color: "lightsteelblue"

        // RGB string
        color: '#FFFFFF'

//        // Random (JavaScript)
//        color: Qt.rgba(Math.random(), Math.random(), Math.random())

        radius: 8
        border {
            color: "lightsteelblue"
            width: 4
        }
    }
}
