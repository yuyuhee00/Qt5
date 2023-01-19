import QtQuick 2.0

Item {
    width: 400
    height: 400

    Component {
        id: myComponent
        Text { text: modelIndex }
    }

    ListView {

        anchors.fill: parent

        model: 5
        delegate: Component {
            Loader {
                property int modelIndex: index
                sourceComponent: myComponent
            }
        }
    }
}

