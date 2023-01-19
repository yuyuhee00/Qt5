import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    Canvas {
        id: root
        // canvas size
        width: 200; height: 200
    }
}
