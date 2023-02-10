import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    width: 250; height: 250; visible: true
    color: "black"

    CircularGauge {
        id: myCircular
        value: accelerating ? maximumValue : 0
        anchors.centerIn: parent

        property bool accelerating: false

        Keys.onSpacePressed: {
            accelerating = true
            console.log("value:" + value.toPrecision(2))
        }

        Keys.onReleased: {
            if (event.key === Qt.Key_Space) {
                accelerating = false;
                event.accepted = true;
            }
        }

        // 해당 Type의 fucus를 활성화
        Component.onCompleted: forceActiveFocus()

        Behavior on value {
            NumberAnimation {
                duration: 1000
            }
        }
    }
}
