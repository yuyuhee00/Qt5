import QtQuick
import QtQuick.Window

Window {
    width: 200; height: 200; visible: true

    Loader {
        id: pageLoader
        anchors.top: myRect.bottom
    }

    Rectangle {
        id: myRect
        width: 200; height: 100
        color: "yellow"
        Text {
            anchors.centerIn: parent
            text: "Main QML"
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                pageLoader.source = "gradient.qml"
            }
        }
    }
}
