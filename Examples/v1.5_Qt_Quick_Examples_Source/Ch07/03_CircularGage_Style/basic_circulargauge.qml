import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    width: 250; height: 250; visible: true
    color: "black"

    CircularGauge {
        id: myCircular
        value: 40
        anchors.centerIn: parent
    }
}
