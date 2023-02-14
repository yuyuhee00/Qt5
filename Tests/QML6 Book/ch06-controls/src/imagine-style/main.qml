import QtQuick
import QtQuick.Controls

ApplicationWindow {

    // ...

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10

        width: parent.width/2

        spacing: 10

        // ...

        Repeater {
            model: 5

            // Button image : Control-Element-State Pattern
            // The stateless file , button-background.9.png is used for all state without a specific asset.


            delegate: Button {
                width: parent.width
                height: 70
                text: qsTr("Click me!")
            }
        }
    }

    Grid {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 10

        columns: 2

        spacing: 10

        // ...

        Repeater {
            model: 10

            // Button image : Control-Element-State Pattern
            // The stateless file , button-background.9.png is used for all state without a specific asset.
            // Button have the states : disabled, pressed, checked, checkable, focused, highlited, flat, irrrored, hovered

            delegate: Button {
                height: 70
                text: qsTr("Check me!")
                checkable: true
            }
        }
    }
}
