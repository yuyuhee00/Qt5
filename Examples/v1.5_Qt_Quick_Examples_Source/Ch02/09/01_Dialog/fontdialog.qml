import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    width: 300; height: 300; visible: true
    Button { text: "FontDialog loading";
             onClicked: { fontDialog.visible = true }
    }
    FontDialog {
        id: fontDialog
        title: "Please choose a font"
        font: Qt.font({ family: "Arial", pointSize: 24, weight: Font.Normal })
        onAccepted: {
            console.log("You chose: " + fontDialog.font)
            Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
        Component.onCompleted: visible = true
    }
}


