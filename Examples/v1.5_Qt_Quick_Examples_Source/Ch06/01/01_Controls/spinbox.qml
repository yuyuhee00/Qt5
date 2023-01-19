import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300
    height: 100
    visible: true

    SpinBox {
        anchors.centerIn: parent
        id: spinbox
        decimals: 2

        maximumValue: 200
        minimumValue: 20
    }
}
