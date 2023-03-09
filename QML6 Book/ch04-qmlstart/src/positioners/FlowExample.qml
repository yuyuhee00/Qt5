import QtQuick

BrightSquare {
    id: root
    width: 160
    height: 160

    Flow {
        anchors.fill: parent
        anchors.margins: 20
        flow: Qt.RightToLeft
        spacing: 20
        RedSquare { }
        BlueSquare { }
        GreenSquare { }
    }
}
