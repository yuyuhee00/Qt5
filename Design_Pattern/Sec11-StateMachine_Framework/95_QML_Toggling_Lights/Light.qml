import QtQuick 2.0

Item {
    id: element
    property color colorOn: "red"
    property color colorOff: "grey"

    Rectangle {
        id: rectangle
        color: colorOff
        radius: width
        anchors.fill: parent
    }
    states: [
        State {
            name: "on"

            PropertyChanges {
                target: rectangle
                color: colorOn
            }
        },
        State {
            name: "off"
            PropertyChanges {
                target: rectangle
                color: colorOff
            }
        }
    ]

}
