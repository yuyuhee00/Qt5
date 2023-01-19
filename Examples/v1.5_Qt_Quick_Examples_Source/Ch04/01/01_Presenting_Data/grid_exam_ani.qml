import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300; height: 200; visible: true

    ListModel {
        id: gridModel
        ListElement {
            name: "Picture 1"; frame: "images/101.JPG"
        }
        ListElement {
            name: "Picture 2"; frame: "images/102.JPG"
        }
        ListElement {
            name: "Picture 3"; frame: "images/103.JPG"
        }
        ListElement {
            name: "Picture 4"; frame: "images/104.JPG"
        }
    }

    Component {
        id: highlight
        Rectangle {
            width: view.cellWidth; height: view.cellHeight
            color: "lightsteelblue"; radius: 5
            x: view.currentItem.x
            y: view.currentItem.y
            Behavior on x { SpringAnimation { spring: 3; damping: 0.2 } }
            Behavior on y { SpringAnimation { spring: 3; damping: 0.2 } }
        }
    }

    GridView {
        id: view
        width: 300; height: 200
        cellWidth: 80; cellHeight: 80

        model: gridModel
        delegate: Column {
            Image {
                width: 60; height: 50; source: frame;
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: name;
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        highlight: highlight
        highlightFollowsCurrentItem: true // current 아이템에 사이즈가 일치하도록 설정
        focus: true
    }
}
