import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 200; height: 200

    Component {
        id: redSquare
        Rectangle { color: "red"; width: 100; height: 100 }
    }

    Loader { sourceComponent: redSquare }
    Loader { sourceComponent: redSquare; x: 100; y: 100}
}
