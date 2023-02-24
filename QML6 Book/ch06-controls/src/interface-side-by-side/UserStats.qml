import QtQuick
import QtQuick.Controls

Page {
    header: Label {
        text: qsTr("Your Stats")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("User statistics")
        anchors.centerIn: parent

        MouseArea {
            anchors.fill: parent
            onClicked:  function () {
                console.log("DClicked", swipeView.currentIndex)
                swipeView.decrementCurrentIndex()
            }
        }
    }
}
