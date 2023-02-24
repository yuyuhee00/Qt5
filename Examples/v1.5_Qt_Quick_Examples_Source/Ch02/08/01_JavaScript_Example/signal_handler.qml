import QtQuick
import QtQuick.Controls

Window  {
    width: 200; height: 80
    visible: true

    signal messageReceived(string person, string notice)

    MouseArea {
        anchors.fill: parent
        onClicked: {
            messageReceived("song", "Merong")
        }
    }

    Component.onCompleted: {
        messageReceived.connect(sendToPost)
    }

    function sendToPost(person, notice)
    {
        console.log("Send to post: " + person + ", " + notice)
    }
}
