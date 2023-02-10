import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("Button Action")
    width: 380; height: 320; visible: true

    ColumnLayout{
        anchors.centerIn: parent
        Button { action: actionButtonA }
        Button { action: actionButtonB }
    }

    Action{
        id: actionButtonA; text: "Button A"
        onTriggered: statusLabel.text = "Button A Triggered "
    }

    Action{
        id: actionButtonB; text: "Button B"
        checkable: true
        onCheckedChanged:
            statusLabel.text = "Button B checked: " + checked
    }

    statusBar: StatusBar{
        Label{ id: statusLabel; text: "Status Bar" }
    }
}
