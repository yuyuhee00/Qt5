import QtQuick 2.12 as MyQt
import QtQuick.Window 2.12

Window {
     visible: true; width: 250; height: 100; color: "lightblue"

    MyQt.Rectangle {
           width: 250; height: 100; color: "lightblue"
           MyQt.Text {
               anchors.centerIn: parent
               text: "Hello Qt!"; font.pixelSize: 32
           }
    }
}

