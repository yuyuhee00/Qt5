import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    width: 200
    height: 100
    visible: true

    toolBar: ToolBar {
        RowLayout {
            ToolButton {
                iconSource: "images/new.png"
            }
            ToolButton {
                iconSource: "images/open.png"
            }
            ToolButton {
                iconSource: "images/paste.png"
            }

            CheckBox {
                text: "Enabled"
                checked: true
            }
        }
    }
}
