import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 240
    height: 300

    ListView {
        anchors.fill: parent
        anchors.margins: 20

        clip: true

        model: 4
        delegate: numberDelegate

        header: headerComponent
        footer: footerComponent

//        orientation: ListView.Horizontal
        spacing: 2
    }

    Component {
        id: headerComponent

        YellowBox {
//            anchors.centerIn: parent
            width: ListView.view ? ListView.view.width : 0
            height: 20
            text: 'Header'
        }
    }

    Component {
        id: footerComponent

        YellowBox {
            anchors.bottom: rec.bottom
            width: ListView.view ? ListView.view.width : 0
            height: 20
//            anchors.topMargin: 100
            text: 'Footer'
        }
    }

    Component {
        id: numberDelegate

        GreenBox {
            required property int index
            
            width: ListView.view.width
            height: 40
            
            text: 'Item #' + index
        }
    }
}
