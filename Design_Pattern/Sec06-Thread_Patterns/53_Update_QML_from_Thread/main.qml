import QtQuick
import QtQuick.Window
import QtQuick.Controls
import com.company.filescanner 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        txtPath.text = scanner.path
    }

    FileScanner {
        id: scanner
        onScanStarted: {
            btnScan.enabled = false
            lblStatus.text = "Starting..."
        }
        onScanUpdated: function(value) {
             lblStatus.text = "Scanning: " + value
        }
        onScanFinished: function(value) {
            btnScan.enabled = true
            lblStatus.text = "Total: " + value
        }
    }

    Column {
        id: column
        width: 323
        height: 145
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Label {
            id: label
            text: qsTr("Path")
        }

        Row {
            id: row
            width: 200
            height: 75
            spacing: 10

            TextField {
                id: txtPath
                text: qsTr("Text Field")
            }

            Button {
                id: btnScan
                text: qsTr("Scan")
                onClicked: scanner.scan(txtPath.text)
            }
        }

        Label {
            id: lblStatus
            text: qsTr("Status Idle")
            font.pointSize: 15
            font.bold: true
        }
    }
}
