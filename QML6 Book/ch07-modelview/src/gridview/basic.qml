import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 220
    height: 300

    GridView {
        id: view
        anchors.fill: parent
        anchors.margins: 20

        clip: true
//        flow: GridView.FlowTopToBottom

        model: 100

        cellWidth: 45
        cellHeight: 45

//        header: headerComponent
//        footer: footerComponent

        delegate: GreenBox {
            required property int index
            width: 40
            height: 40
            text: index
        }
    }

    Component {
        id: headerComponent

        YellowBox {
//            width: GridView.view ? GridView.view.width : 0
            height: 20
            text: 'Header'
        }
    }

    Component {
        id: footerComponent

        YellowBox {
//            width: GridView.view ? GridView.view.width : 0
            height: 20
            text: 'Footer'
        }
    }

}
