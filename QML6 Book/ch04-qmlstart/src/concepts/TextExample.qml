import QtQuick

Rectangle {
    width: 400
    height: 120

    Rectangle {
        id: back
        implicitWidth: text.implicitWidth; implicitHeight: text.implicitHeight
        color: '#FF0000'
        radius: 5

        Text {
            id: text
            text: "The quick brown fox"
            color: "#303030"
            font.family: "Ubuntu"
            font.pixelSize: 28
            horizontalAlignment: Text.Center
            verticalAlignment: Text.Center
        }
    }
}
