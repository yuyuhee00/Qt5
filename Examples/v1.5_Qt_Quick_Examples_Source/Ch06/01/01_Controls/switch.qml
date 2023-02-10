import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 100
    height: 100
    visible: true

    Column {
        anchors.centerIn: parent
        spacing: 5
        Switch {
            id: first
            checked: true
            onClicked: {
                if(checked === true)
                    console.log("first checked true");
                else
                    console.log("first checked false")
            }

        }
        Switch { checked: false }
    }
}
