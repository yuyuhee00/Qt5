import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtQuick.Window
import "."

Dialog {

    property string label: "New item"
    property string hint: ""
    property alias editText : editTextItem

//    standardButtons: StandardButton.Ok | StandardButton.Cancel
    standardButtons: Dialog.Ok | Dialog.Cancel
    onVisibleChanged: {
        editTextItem.focus = true
        editTextItem.selectAll()
    }

//    onButtonClicked: {
//        Qt.inputMethod.hide();
//    }

    onAccepted: {
        Qt.inputMethod.hide();
    }

    Rectangle {

        implicitWidth: parent.width
        implicitHeight: 100

        ColumnLayout {
            Text {
                id: labelItem
                text: label
                color: Style.text
            }

            TextInput {
                id: editTextItem
                inputMethodHints: Qt.ImhPreferUppercase
                text: hint
                color: Style.text
            }
        }
    }
}
