import QtQuick
import "../common"

Background {
    width: 80
    height: 300

    ListView {
        anchors.fill: parent
        anchors.margins: 20
        clip: true
        snapMode: ListView.SnapToItem

        model: 100
        delegate: GreenBox {
            required property int index
            width: 40
            height: 40
            text: index

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked : " + index)
                }
            }
        }
        spacing: 5
    }
}
