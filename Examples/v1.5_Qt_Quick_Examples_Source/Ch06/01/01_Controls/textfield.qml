import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 200
    height: 100
    visible: true

    TextField {
        validator: IntValidator {bottom: 11; top: 31;}
        focus: true
        anchors.centerIn: parent
    }
}
