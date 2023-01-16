import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml.StateMachine 1.0 as DSM

Window {
    id: window
    visible: true
    width: 640
    height: 480
    // @disable-check M16
    title: qsTr("Hello World")

    DSM.StateMachine
    {
        id:statemachine
        // @disable-check M16
        initialState: state1
        running: true

        DSM.State {
            id: state1
            // @disable-check M16
            onEntered: label.text = "State 1"
            DSM.SignalTransition {
                // @disable-check M16
                targetState: state2
                signal:  next.clicked
            }
            DSM.SignalTransition {
                // @disable-check M16
                targetState: state3
                signal:  before.clicked
            }
        }

        DSM.State {
            id: state2
            // @disable-check M16
            onEntered: label.text = "State 2"
            DSM.SignalTransition {
                // @disable-check M16
                targetState: state3
                signal:  next.clicked
            }
            DSM.SignalTransition {
                // @disable-check M16
                targetState: state1
                signal:  before.clicked
            }
        }

        DSM.State {
            id: state3
            // @disable-check M16
            onEntered: label.text = "State 3"
            DSM.SignalTransition {
                // @disable-check M16
                targetState: state1
                signal:  next.clicked
            }
            DSM.SignalTransition {
                // @disable-check M16
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
