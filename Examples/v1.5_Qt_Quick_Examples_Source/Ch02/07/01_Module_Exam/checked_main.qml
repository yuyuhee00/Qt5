import QtQuick
import "content"

Window {
    id: root
    visible: true; width: 250; height: 100
    color: "lightblue"

    NewCheckBox {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onMyChecked: checkValue ? root.color = "red"  :  root.color = "lightblue"
    }
}
