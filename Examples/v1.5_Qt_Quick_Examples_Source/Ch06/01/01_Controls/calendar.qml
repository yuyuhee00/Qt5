import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow
{
    title: qsTr("Calendar controls")
    width: 300
    height: 300
    visible: true

    Calendar {
        width: parent.width
        height: parent.height
        weekNumbersVisible: true
    }
}
