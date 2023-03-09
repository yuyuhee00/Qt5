import QtQuick

BrightSquare {
    id: root
    width: 400; height: 120

    Row {
        id: row
        anchors.centerIn: parent
        layoutDirection: Qt.RightToLeft
        spacing: 20
        BlueSquare { }
        GreenSquare { }
        RedSquare { }
    }
}
// #endregion global
