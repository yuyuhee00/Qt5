import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300; height: 300; visible: true

    Column {
        anchors.centerIn: parent
        ProgressBar {
            value: 0.5
        }

        ProgressBar {
            indeterminate: true
            orientation: Qt.Vertical
        }
    }
}
