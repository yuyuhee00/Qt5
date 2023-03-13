import QtQuick
import QtQuick.Controls

// Page component supports header and footer.
Page {
    title: qsTr("Home")

//     header: ToolBar {
//        contentHeight: toolButton.implicitHeight
//        ToolButton {
//            id: toolButton
//            text: "=="
//        }
//        Label {
//            anchors.centerIn: parent
//            text: qsTr("Home Heder")
//        }
//     }

     Label {
         anchors.centerIn: parent
         text: qsTr("Home Screen")
     }
}
