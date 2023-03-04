import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 240
    height: 300

    ListView {
        id: view

        anchors.fill: parent
        anchors.margins: 20
        spacing: 5
        clip: true

        focus: true
        highlight: highlightComponent

        model: 100
        delegate: numberDelegate

        header: headerComponent
        footer: footerComponent
    }

    Component {
        id: headerComponent

        YellowBox {
            width: ListView.view ? ListView.view.width : 0
            height: 20
            text: 'Header'

        }
    }

    Component {
        id: footerComponent

        YellowBox {
            width: ListView.view ? ListView.view.width : 0
            height: 20
            text: 'Footer'
        }
    }

    Component {
        id: highlightComponent

        GreenBox {
            width: ListView.view ? ListView.view.width : 0
        }
    }

    Component {
        id: numberDelegate

        Item {
            id: wrapper

            required property int index

            width: ListView.view ? ListView.view.width : 0
            height: 40

            Text {
                anchors.centerIn: parent
                font.pixelSize: 10
                text: wrapper.index
            }
        }
    }
}
