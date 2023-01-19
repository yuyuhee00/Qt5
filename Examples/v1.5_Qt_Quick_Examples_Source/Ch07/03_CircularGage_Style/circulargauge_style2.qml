import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    width: 250; height: 250; visible: true
    color: "#494d53"

    CircularGauge {
        id: gauge
        value: 40
        anchors.centerIn: parent
        style: CircularGaugeStyle {
            id: style
            needle: Rectangle {
                y: outerRadius * 0.15
                implicitWidth: outerRadius * 0.03
                implicitHeight: outerRadius * 0.9
                antialiasing: true
                color: "#e5e5e5"
            }

            foreground: Item {
                Rectangle {
                    width: outerRadius * 0.2
                    height: width
                    radius: width / 2
                    color: "green"
                    anchors.centerIn: parent
                }
            }
        }
    }
}
