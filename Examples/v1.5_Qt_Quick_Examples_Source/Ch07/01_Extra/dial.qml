import QtQuick 2.12
import QtQuick.Controls 1.3
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    width: 400; height: 200; visible: true

    RowLayout {
        anchors.centerIn: parent
        Dial {
            id: myDial1
            minimumValue: 0; maximumValue: 100
            tickmarksVisible: false
            stepSize: 20
            onValueChanged: {
                console.log('value:' + value)
            }
        }
        Dial {
            width: 200; height: 200
            id: myDial2
            minimumValue: 0; maximumValue: 20; stepSize: 2
            onValueChanged: {
                console.log('value:' + value)
            }
        }
        Dial {
            width: 200; height: 200
            id: myDial3
            minimumValue: 0; maximumValue: 60; stepSize: 2
            onValueChanged: {
                console.log('value:' + value)
            }
        }
    }
}
