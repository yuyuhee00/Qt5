import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

ApplicationWindow {
    width: 200; height: 200; visible: true

    ColumnLayout {
        anchors.centerIn: parent; spacing: 6
        Button { text: "My Byttoon" }
        Button {
            text: "A button"
            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 25
                    border.width: control.activeFocus ? 2 : 1
                    border.color: "#888"
                    radius: 4
                    gradient: Gradient {
                        GradientStop {
                            position: 0
                            color: control.pressed ? "#ccc" : "#eee"
                        }
                        GradientStop {
                            position: 1
                            color: control.pressed ? "#aaa" : "#ccc"
                        }
                    }
                }
            }
        }
    }
}
