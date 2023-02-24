import QtQuick
import QtQuick.Controls

Window {
    id: colorButton
    width: 200; height: calculateHeight()
    color: mousearea.pressed ? "steelblue" : "lightsteelblue"
    title: qsTr("Hello World")
    visible: true

    MouseArea {
        id: mousearea
        anchors.fill: parent
        onDoubleClicked: {
//            item1.visible = true
            item2.visible = true
        }
    }

    function calculateHeight()
    {
        return colorButton.width / 2;
    }

    Item {
        id: item1
        width: parent.width
        height: parent.height
        visible: false

        MouseArea {
            anchors.fill: parent
            onClicked: label.moveTo(mouseX, mouseY)
        }

        Text {
            id: label
            text: "Move Me"

            function moveTo(newX, newY)
            {
                label.x = newX
                label.y = newY
            }
        }
    }

    Item {
        id: item2
        width: parent.width
        height: parent.height
        visible: false

        function factorial(a) {
            a = parseInt(a)
            if(a <= 0)
                return 1
            else
                return a * factorial(a-1)
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log(item2.factorial(3))
            }
        }
    }
}
