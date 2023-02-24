import QtQuick
import QtQuick.Controls

// Page component supports header and footer.
Page {
    title: qsTr("Home")

    Label {
        anchors.centerIn: parent
        text: qsTr("Home Screen")
    }
}
