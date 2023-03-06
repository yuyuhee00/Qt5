import QtQuick

Item {
    id: window
    width: background.width
    height: background.height

    Image {
        id: background
        source: "images/background.png"
    }

    Image {
        id: pinwheel
        anchors.centerIn: parent
        source: "images/pinwheel.png"
    }
}
