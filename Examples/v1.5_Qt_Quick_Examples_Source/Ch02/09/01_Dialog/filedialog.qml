import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {
    width: 300; height: 300; visible: true

    Button {
        text: "FileDialog loading"
        onClicked: {
            fileDialog.visible = true
        }
    }

    FileDialog
    {
        id: fileDialog
        title: "Please choose a file"
//        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }

        Component.onCompleted: visible = false
    }
}


