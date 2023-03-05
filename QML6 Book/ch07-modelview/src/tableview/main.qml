import QtQuick
import QtQuick.Controls
import "../common"

Window {
    width: 320
    height: 320

    visible: true

    Background {
        anchors.fill: parent

        TableView {
            id: view

            anchors.fill: parent
            anchors.margins: 20

            rowSpacing: 5
            columnSpacing: 5

            clip: true

            //
            // It is not possible to create table oriented models directly from QML
            //
            model: tableModel
            delegate: cellDelegate
        }
    }

    Component {
        id: cellDelegate

        GreenBox {
            id: wrapper

            //
            // Display Role
            //
            required property string display

            implicitHeight: 40
            implicitWidth: 40

            Text {
                anchors.centerIn: parent
                text: wrapper.display
            }
        }
    }
}
