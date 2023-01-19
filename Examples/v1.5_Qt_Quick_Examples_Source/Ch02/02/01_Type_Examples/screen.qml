import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    // Ex) Monitor Resolution 1920 x 1080
    //      width  = 1920 / 2
    //      height = 1080 / 2
    width : Screen.width / 2;
    height : Screen.height / 2;

    Rectangle {
        width : 300
        height: 200
        color: "blue"

        anchors.centerIn: parent
    }
}



