import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    visible: true
    width: 200; height: 200

    Loader {
        id: squareLoader
        onLoaded: {
            console.log("Width : " + squareLoader.item.width);
        }
    }
    Component.onCompleted: {
        squareLoader.setSource( "ExComponent.qml", { "color": "blue" } )
    }

    Rectangle {
        anchors.top: squareLoader.bottom
        width: 200; height: 100
        color: "green"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                squareLoader.setSource( "ExComponent.qml", {"width": 200} )
            }
        }
    }
}
