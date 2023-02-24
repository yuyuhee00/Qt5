import QtQuick
import QtQuick.Controls

Window {
    id: colorButton
    width: 200; height: 80
    color: "red"
    title: qsTr("Hello World")
    visible: true

    MouseArea {
        id: mousearea
        anchors.fill: parent
    }

    Component.onCompleted: {
        color = Qt.binding(function() {
            console.log("function_binding")
            return mousearea.pressed ? "steelblue" : "lightsteelblue"
        })
    }
}

