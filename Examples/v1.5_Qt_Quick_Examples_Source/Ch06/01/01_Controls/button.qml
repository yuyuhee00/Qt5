import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow
{
    title: qsTr("Hello World")
    width: 200
    height: 200
    visible: true

    Button {
        anchors.centerIn: parent
        text: "Button"
        tooltip: "Description"
    }
}
