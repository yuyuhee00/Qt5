import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 200; height: 70; visible: true

    ListModel {
        id: fruitModel
        ListElement { name: "Apple";  cost: 2.45 }
        ListElement { name: "Orange"; cost: 3.25 }
        ListElement { name: "Banana"; cost: 1.95 }
    }
    Component {
        id: fruitDelegate
        Row {
            spacing: 10
            Text { text: name }
            Text { text: '$' + cost }
        }
    }
    ListView {
        anchors.fill: parent
        model: fruitModel
        delegate: fruitDelegate
    }
}
