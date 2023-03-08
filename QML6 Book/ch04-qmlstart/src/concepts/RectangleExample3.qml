import QtQuick

Item {
    width: 200
    height: 120

    Rectangle {
        id: rect1
        x: 12; y: 12
        width: 176; height: 96
//        anchors.fill: parent

        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightsteelblue" }
//            GradientStop { position: 0.5; color: "blue" }
            GradientStop { position: 1.0; color: "slategray" }
        }

        radius: 4

        border {
            color: "slategray"
            width: 2
        }
    }
}
