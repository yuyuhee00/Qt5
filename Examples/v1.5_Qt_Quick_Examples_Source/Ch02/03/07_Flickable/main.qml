import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true
    width: 640; height: 480

    Rectangle {
        width: 640
        height: 480

        Flickable {
            id: view
            anchors.fill: parent
            contentWidth: picture.width
            contentHeight: picture.height

            Image {
                 id: picture
                 source: "images/background.jpg"
            }
         }
    }
}
