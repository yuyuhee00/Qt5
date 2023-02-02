import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        light1.state = "on"
        light2.state = "off"
    }

    function toggle(obj)
    {
        if(obj.state === "on")
        {
            obj.state = "off"
        } else {
            obj.state = "on"
        }
    }

    function enforce(primary, secondary)
    {
        console.log(primary.state)
        if(primary.state === "on")
        {
            secondary.state = "off"
        } else {
            secondary.state = "on"
        }
    }

    Row {
        width:  300
        height: 100
        anchors.centerIn: parent
        spacing: 100

        Light {
            id: light1
            width: 100
            height: 100
            state: "off"
            onStateChanged: enforce(light1,light2)
            MouseArea {
                anchors.fill: parent
                onClicked: toggle(parent)
            }

        }

        Light {
            id: light2
            width: 100
            height: 100
            state: "off"
            onStateChanged: enforce(light2,light1)
            MouseArea {
                anchors.fill: parent
                onClicked: toggle(parent)
            }

        }
    }

}


