import QtQuick

Item {
    id: root
    width: background.width; height: background.height

    Image {
        id: background
        source: "assets/background_medium.png"
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
        source: "assets/box_green.png"
        text: qsTr("animation on property")

        NumberAnimation on y {
            to: 40; duration: 4000
        }
    }

    ClickableImageV2 {
        id: blueBox
        x: (root.width-width)/2; y: root.height-height
        source: "assets/box_blue.png"
        text: qsTr("behavior on property")

        onClicked: y = 40
        // random y on each click
        // onClicked: y = 40 + Math.random() * (205-40)

        Behavior on y {
            NumberAnimation { duration: 4000 }
        } 
    }

    ClickableImageV2 {
        id: redBox
        x: root.width-width-40; y: root.height-height
        source: "assets/box_red.png"
        text: qsTr("standalone animation")

        onClicked: anim.start()
        // onClicked: anim.restart()

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 40
            duration: 4000
        }
    }
}

