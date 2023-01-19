import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 200; height: 80

    Rectangle {
        width: 200; height: 80
        color: myPalette.window

        SystemPalette {
            id: myPalette
            colorGroup: SystemPalette.Active
        }

        Text {
            id: myText
            anchors.fill: parent
            text: "Hello!";
            font.pixelSize: 32
            color: myPalette.windowText
        }
    }
}
