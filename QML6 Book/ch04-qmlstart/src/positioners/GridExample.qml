import QtQuick

BrightSquare {
    id: root
    width: 160
    height: 160

    Grid {
        id: grid
        rows: 3
        columns: 2
        anchors.centerIn: parent
        layoutDirection: Qt.RightToLeft
        spacing: 8
        RedSquare { }
        BlueSquare { }
        GreenSquare { }
        RedSquare { }
        BlueSquare { }
    }
}
