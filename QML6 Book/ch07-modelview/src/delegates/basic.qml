import QtQuick
import QtQuick.Controls

Rectangle {
    width: 120
    height: 300

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#f6f6f6" }
        GradientStop { position: 1.0; color: "#d7d7d7" }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 5
        clip: true
        focus: true

        model: 100
        delegate: numberDelegate
    }

    Component {
        id: numberDelegate

//        // Component can not declare new properties.
//        required property int index

        Rectangle {
            id: wrapper

            required property int index

            width: ListView.view.width
            height: 40

            color: ListView.isCurrentItem ? "#157efb" : "#53d769"
            border.color: Qt.lighter(color, 1.1)

            Text {
                anchors.centerIn: parent
                font.pixelSize: 10
                text: wrapper.index
            }
        }
    }
}
