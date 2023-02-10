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
        id: contactDelegate
        Item {
            width: grid.cellWidth; height: grid.cellHeight
            Column {
                anchors.fill: parent
                Image {
                    width: 80; height: 50
                    source: frame;
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: name;
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    GridView {
        id: grid
        anchors.fill: parent
        cellWidth: 90; cellHeight: 90

        model: gridModel
        delegate: contactDelegate
        highlight:
            Rectangle {
                color: "lightsteelblue"; radius: 5
            }
        focus: true
    }
}
