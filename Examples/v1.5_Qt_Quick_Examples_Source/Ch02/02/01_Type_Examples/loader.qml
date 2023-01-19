import QtQuick 2.0

Item {
    width: 200; height: 200

    Loader { id: pageLoader }

    MouseArea {
        anchors.fill: parent
        onClicked: pageLoader.source = "gradient.qml"
    }
}
