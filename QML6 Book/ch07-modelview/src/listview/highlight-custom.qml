import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 240
    height: 300

    ListView {
        id: view
        anchors.fill: parent
        anchors.margins: 20
//        currentIndex: 0
        spacing: 4
        clip: true

        highlight: highlightComponent
        highlightFollowsCurrentItem: false
        focus: true

        model: 100
        delegate: numberDelegate
    }

    Component {
        id: highlightComponent

        Item {
            width: ListView.view ? ListView.view.width : 0
            height: ListView.view ? ListView.view.currentItem.height : 0

            y: ListView.view ? ListView.view.currentItem.y : 0

            Behavior on y {
                SequentialAnimation {
                    PropertyAnimation { target: highlightRectangle; property: "opacity"; to: 0; duration: 200 }
                    NumberAnimation { duration: 1 }
                    PropertyAnimation { target: highlightRectangle; property: "opacity"; to: 1; duration: 200 }
                }
            }

            GreenBox {
                id: highlightRectangle
                anchors.fill: parent
            }
        }
    }

    Component {
        id: numberDelegate

        Item {
            width: 40
            height: 40

//            required property int index

            Text {
                anchors.centerIn: parent
                font.pixelSize: 14
                text: index  // qmllint disable unqualified
            }
        }
    }
}
