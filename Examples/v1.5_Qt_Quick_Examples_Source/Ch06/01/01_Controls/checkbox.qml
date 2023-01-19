import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow
{
    title: qsTr("Checkbox controls")
    width: 100
    height: 100
    visible: true

    Column {
        anchors.centerIn: parent

        CheckBox {
            text: qsTr("Breakfast")
            checked: true
        }
        CheckBox {
            text: qsTr("Lunch")
        }
        CheckBox {
            text: qsTr("Dinner")
            checked: true
        }
    }
}
