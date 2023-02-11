import QtQuick
import "./Ch05"

Item {
    id: root
    width: background.width; height: background.height

    Image {
        id: background
        source: "assets/ch05/background.png"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            greenBox.y = blueBox.y = redBox.y = 205
        }
    }

    ClickableImageV2 {
        id: greenBox
        x: 40; y: root.height-height
        source: "../assets/ch05/box_green.png"
        text: qsTr("animation on property")

         // reset y, does not have any effect as long as the animation is running.
        NumberAnimation on y {
            to: 40; duration: 4000
        }
    }

    ClickableImageV2 {
        id: blueBox
        x: (root.width-width)/2; y: root.height-height
        source: "../assets/ch05/box_blue.png"
        text: qsTr("behavior on property")

        // property y, should be animate each change in value
        Behavior on y {
            NumberAnimation { duration: 4000 }
        }

        onClicked: y = 40
        // random y on each click
        // onClicked: y = 40 + Math.random() * (205-40)
    }

    ClickableImageV2 {
        id: redBox
        x: root.width-width-40; y: root.height-height
        source: "../assets/ch05/box_red.png"
        onClicked: anim.start()
        //onClicked: anim.restart()

        text: qsTr("standalone animation")

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 40
            duration: 4000
        }
    }
}
