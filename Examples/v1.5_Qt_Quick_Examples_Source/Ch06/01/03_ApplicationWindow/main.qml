import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: myWindow; width: 480; height: 320
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
            MenuItem {
                text: "File Item2"
                onTriggered: statusLabel.text = "File Item2 Click"
            }
        }
        Menu {
            title: "Option B"
            MenuItem {
                text: "Opt B1"
                onTriggered: statusLabel.text = "Opt B1 Click"
            }
            MenuItem {
                text: "Opt B2"; checkable: true
                onCheckedChanged:
                    statusLabel.text = "Opt B2 Checked - " + checked
            }
            MenuItem {
                text: "Opt B3"; checkable: true
                onCheckedChanged:
                    statusLabel.text = "Opt B3 Checked - " + checked
            }
        }
    }

    toolBar: ToolBar{
        RowLayout{
            ToolButton{
                text: "ToolButton T1"
                onClicked: statusLabel.text = "ToolButton T1 clicked"
            }
            ToolButton{
                text: "ToolButton T2"
                onClicked: statusLabel.text = "ToolButton T2 clicked"
            }
            ToolButton{
                text: "ToolButton T3"
                onClicked: statusLabel.text = "ToolButton T3 clicked"
            }
        }
    }

    statusBar: StatusBar{
        RowLayout{
            Label{
                id: statusLabel
                text: "Status Bar"
            }
        }
    }
}
