import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true; width: 300; height: 200
    ColorDialog {
        id: colorDialog
        modality: colorDialogModal.checked ? Qt.WindowModal : Qt.NonModal
        title: "Choose a color"; color: "green"
        onAccepted: { console.log("Accepted: " + color) }
        onRejected: { console.log("Rejected") }
    }
    Column {
        anchors.fill: parent; anchors.margins: 12; spacing: 8
        Label { font.bold: true; text: "Color dialog 프로퍼티:" }

        CheckBox {
            id: colorDialogModal; text: "Modal"; checked: true
            Binding on checked { value: colorDialog.modality != Qt.NonModal }
        }
        Rectangle {
            color: colorDialog.color
            height: 50; width: 50; border.color: "black"
            MouseArea { anchors.fill: parent; onClicked: colorDialog.open() }
        }
        Button { text: "다이얼로그 로딩"; onClicked: colorDialog.open() }

    }
}
