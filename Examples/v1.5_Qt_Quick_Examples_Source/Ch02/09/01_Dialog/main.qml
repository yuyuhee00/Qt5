import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {
    width: 300; height: 300; visible: true

    Button {
        text: "Dialog loading"
        onClicked: { myDial.visible = true }
    }

    Dialog {
        id: myDial
        title: "Blue sky dialog"
        visible: false

        contentItem: Rectangle {
            color: "lightskyblue"
            implicitWidth: 200; implicitHeight: 200
            Text {
                text: "Hello blue sky!"; color: "navy"
                anchors.centerIn: parent
            }
        }
    }
}


