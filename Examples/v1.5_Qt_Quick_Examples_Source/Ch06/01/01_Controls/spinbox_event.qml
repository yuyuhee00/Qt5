import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    title: qsTr("SpinBox")
    width: 200; height: 140; visible: true

    Column{
        anchors.centerIn: parent
        spacing: 5

        Label {
            id: label
        }
        SpinBox{
            id: spinbox1; width: 100
            maximumValue: 100; minimumValue: 0; value: 50
            onValueChanged: label.text = "spinbox1: " + value
        }
        SpinBox{
            id: spinbox2; width: 100
            maximumValue: 100; minimumValue: 0;
            value: 50; stepSize: 5; prefix: "prefix: "
            onValueChanged: label.text = "spinbox2: " + value
        }
        SpinBox{
            id: spinbox3;  width: 100;
            maximumValue: 100; minimumValue: 0; value: 50; stepSize: 10
            suffix: "-suffix"
            onValueChanged: label.text = "spinbox3: " + value
        }
    }
}
