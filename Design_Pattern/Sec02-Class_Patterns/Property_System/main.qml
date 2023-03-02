import QtQuick
import QtQuick.Controls
import com.company.machine

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Machine {
        id: machine

        onStarted : {
            lblStatus.text = "Started: " + machine.count + " of " + machine.max
        }
        onPaused: {
            lblStatus.text = "Paused: " + machine.count + " of " + machine.max
        }
        onStopped: {
            lblStatus.text = "Stopped: " + machine.count + " of " + machine.max
        }

        onCountChanged: {
            lblStatus.text = "Running: " + machine.count + " of " + machine.max
        }
        onMaxChanged: {
            lblStatus.text = "Running: " + machine.count + " of " + machine.max
        }
        onNameChanged: {
            console.log("Name Changed: " + machine.name)
        }
    }

    Column {
        id: column
        width: 358
        height: 216
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: lblStatus
            text: qsTr("Status")
            font.pointSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            id: row
            width: 350
            height: 75
            spacing: 25

            Button {
                id: btnStart
                text: qsTr("Start")
                onClicked: {
                    console.log("Start the machine")
                    machine.start()
                }
            }

            Button {
                id: btnPause
                text: qsTr("Pause")
                onClicked: {
                    console.log("Pause the machine")
                    machine.pause()
                }
            }

            Button {
                id: btnStop
                text: qsTr("Stop")
                onClicked: {
                    console.log("Stop the machine")
                    machine.stop()
                }
            }
        }

        Button {
            id: btnTest
            text: qsTr("Test")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                console.log("Clicked test")

                 machine.max = 1000
//                setMax() is in slot:
//                machine.setMax(100)

            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
