import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    width: 350; height: 100
    visible: true
    color: "black"

    Gauge {
        width: 300
        height: 30
        minimumValue: 0
        value: 50
        maximumValue: 100
        //tickmarkAlignment: Qt.AlignTop
        tickmarkAlignment: Qt.AlignBottom
        orientation: Qt.Horizontal
        anchors.centerIn: parent
    }
}

