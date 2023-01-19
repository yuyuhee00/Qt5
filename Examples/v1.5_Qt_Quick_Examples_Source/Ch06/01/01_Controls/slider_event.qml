import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 400; height: 260; visible: true

    Column{
        Label { id: label }

        Slider{
            id: slider1; maximumValue: 100; minimumValue: 0
            value: 50; onValueChanged: label.text = "slider1: " + value
        }
        Slider{
            id: slider2; maximumValue: 100; minimumValue: 0;
            value: 50; stepSize: 10
            onValueChanged: label.text = "slider2: " + value
        }
        Slider{
            id: slider3; maximumValue: 100; minimumValue: 0
            value: 50; stepSize: 25
            orientation: Qt.Vertical
            onValueChanged: label.text = "slider3: " + value
        }
    }
}
