import QtQuick
import QtQuick.Controls
import QtQml.StateMachine as DSM

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DSM.StateMachine
    {
        id:statemachine
        initialState: state1
        running: true

        DSM.State {
            id: state1
            onEntered: label.text = "State 1"
            DSM.SignalTransition {
                targetState: state2
                signal:  next.clicked
            }
            DSM.SignalTransition {
                targetState: state3
                signal:  before.clicked
            }
        }

        DSM.State {
            id: state2
            onEntered: label.text = "State 2"
            DSM.SignalTransition {
                targetState: state3
                signal:  next.clicked
            }
            DSM.SignalTransition {
                targetState: state1
                signal:  before.clicked
            }
        }

        DSM.State {
            id: state3
            onEntered: label.text = "State 3"
            DSM.SignalTransition {
                targetState: state1
                signal:  next.clicked
            }
            DSM.SignalTransition {
                targetState: state2
                signal:  before.clicked
            }
        }
        DSM.FinalState {
            id: f
        }
    }

    Column {
        id: column
        width: 159
        height: 92
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25

        Label {
            id: label
            text: qsTr("Null")
            font.pointSize:  30
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: next
            text: qsTr("Next")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: before
            text: qsTr("Before")
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/
