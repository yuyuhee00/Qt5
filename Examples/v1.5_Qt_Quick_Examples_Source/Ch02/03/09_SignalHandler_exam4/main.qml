import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true; width: 360; height: 360

    id: relay
    signal messageReceived(string person, string notice)

    Component.onCompleted: {
        relay.messageReceived.connect(sendToPost)
        relay.messageReceived.connect(sendToTelegraph)
        relay.messageReceived.connect(sendToEmail)
    }

    function sendToPost(person, notice) {
        console.log("Sending to post: " + person + ", " + notice)
    }
    function sendToTelegraph(person, notice) {
        console.log("Sending to telegraph: " + person + ", " + notice)
    }
    function sendToEmail(person, notice) {
        console.log("Sending to email: " + person + ", " + notice)
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            relay.messageReceived("Tom", "Happy Birthday")
        }
    }
}

