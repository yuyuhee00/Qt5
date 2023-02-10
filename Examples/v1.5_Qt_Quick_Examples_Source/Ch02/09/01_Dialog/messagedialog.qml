import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    width: 300; height: 300; visible: true
    Button { text: "MessageDialog loading";
             onClicked: { messageDialog.visible = true }
    }

    MessageDialog {
        title: "Overwrite?"
        icon: StandardIcon.Question
        text: "파일이 이미지 존재 합니다. "
        detailedText: "기존 파일을 Overwrite 하시겠습니까? "
        standardButtons: StandardButton.Yes | StandardButton.YesToAll |
            StandardButton.No | StandardButton.NoToAll | StandardButton.Abort
        Component.onCompleted: visible = true
        onYes: console.log("copied")
        onNo: console.log("didn't copy")
        onRejected: console.log("aborted")
    }
}


