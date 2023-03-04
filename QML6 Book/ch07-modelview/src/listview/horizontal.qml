import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 480
    height: 80

    ListView {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 4
        clip: true
        snapMode: ListView.SnapToItem

        orientation: ListView.Horizontal
//        layoutDirection: Qt.RightToLeft

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
    }
}
