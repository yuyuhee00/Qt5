import QtQuick

Item {
    id: window
    width: background.width
    height: background.height

    // M1>>
    Image {
        id: background
        source: "images/background.png"
    }
    Image {
        id: pole
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "images/pole.png"
    }
    // <<M1
}
