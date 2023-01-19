import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300
    height: 100
    visible: true

    Slider {
        anchors.centerIn: parent
        value: 2.5
        maximumValue: 5.0
        stepSize: 1.0
    }
}
