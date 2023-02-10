import QtQuick
import QtQuick.Controls
import "." // QTBUG-34418, singletons require explicit import to load qmldir file

ApplicationWindow {

    readonly property alias pageStack: stackView

    id: app
    visible: true
    width: 1024
    height: 768
    color: Style.windowBackground

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: AlbumListPage {}
    }

    onClosing: {
       // if (Qt.platform.os == "android") {
            if (stackView.depth > 1) {
                close.accepted = false
                stackView.pop()
            }
        //}
    }
}
