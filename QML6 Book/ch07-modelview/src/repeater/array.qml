import QtQuick
import "../common"

Column {
    spacing: 2

    Repeater {
        model: ["Enterprise", "Columbia", "Challenger", "Discovery", "Endeavour", "Atlantis"]

        delegate: BlueBox {
            required property var modelData
            required property int index

            width: 100
            height: 32
            radius: 3

            text: modelData + ' (' + index + ')'

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked : " + text)
                }
            }
        }
    }
}
