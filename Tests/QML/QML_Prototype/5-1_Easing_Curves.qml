import QtQuick
import QtQuick.Layouts
import "./Ch05"

Rectangle {
    id: root
    width: childrentRect.width
    height: childrenRect.height
    color: "#4a4a4a"
    gradient: Gradient {
        GradientStop { position: 0.0; color: root.color }
        GradientStop { position: 1.0; color: Qt.lighter(root.color) }
    }

    ColumnLayout {
        Grid {
            spacing: 8; columns: 5
            EasingType {
                easingType:
            }
        }
    }
}
