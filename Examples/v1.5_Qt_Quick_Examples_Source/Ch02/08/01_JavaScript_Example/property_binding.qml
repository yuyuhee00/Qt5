import QtQuick

Window {
    id: colorButton
    width: 200; height: 80
    color: mousearea.pressed ? "steelblue" : "lightsteelblue"
    title: qsTr("Hello World")
    visible: true

    MouseArea {
        id: mousearea
        anchors.fill: parent
    }
}
