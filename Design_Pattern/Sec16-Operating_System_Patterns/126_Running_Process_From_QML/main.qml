import QtQuick
import QtQuick.Window
import QtQuick.Controls
import com.company.task 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Task {
        id: task

//        onReadyReadStandardOutput: {
//           txtOut.text = task.readAllStandardOutput();
//            console.log(txtOut.text)
//        }

        onReadyRead: {
            txtOut.text = task.readAll();
            console.log(txtOut.text)
        }
    }

    Column {
        id: column
        width: 296
        height: 243
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25

        Grid {
            spacing: 25
            rows: 3

            Label {
                text: qsTr("Command")
            }

            TextField {
                id: txtCommand
                text: qsTr("echo")
            }

            Label {
                text: qsTr("Args")
            }
            TextField {
                id: txtArg
                text: qsTr("hello world")
            }

            Label {
                text: qsTr("Output")
            }
            TextField {
                id: txtOut
            }
        }

        Button {
            id: button
            text: qsTr("Go")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                task.start(txtCommand.text, [txtArg.text])
            }
        }
    }
}
