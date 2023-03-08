import QtQuick

//Item {
Rectangle {
    width: 400
    height: 120

    Rectangle {
        id: back
        implicitWidth: text.implicitWidth; implicitHeight: text.implicitHeight
//        anchors.fill: parent
        color: '#FF0000'
        radius: 5

        Text {
            id: text
            text: "The quick brown fox"
            color: "#303030"
            horizontalAlignment: Text.Center
            verticalAlignment: Text.Center
            font {
                family: "Ubuntu"
                pixelSize: 28
            }
        }
    }
}
