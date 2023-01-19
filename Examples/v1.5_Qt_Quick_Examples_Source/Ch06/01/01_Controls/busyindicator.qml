import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow
{
    title: qsTr("Hello World")
    width: 300
    height: 300
    visible: true

    BusyIndicator
    {
        anchors.centerIn: parent
        running: true
    }
}
