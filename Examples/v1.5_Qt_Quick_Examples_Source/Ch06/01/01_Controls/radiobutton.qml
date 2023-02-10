import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

ApplicationWindow
{
    width: 200; height: 70; visible: true
    GroupBox {
        title: "Tab Position"
        anchors.centerIn: parent
        RowLayout {
            RadioButton {
                text: "Top"
                checked: true
            }
            RadioButton {
                text: "Bottom"
            }
        }
    }
}
