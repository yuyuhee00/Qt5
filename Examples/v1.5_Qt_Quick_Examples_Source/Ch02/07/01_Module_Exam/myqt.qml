import QtQuick as MyQt

MyQt.Window {
     visible: true; width: 250; height: 100; color: "lightblue"

    MyQt.Rectangle {
           width: 250; height: 100; color: "lightblue"

           MyQt.Text {
               anchors.centerIn: parent
               text: "Hello Qt!"; font.pixelSize: 32
           }
    }
}

