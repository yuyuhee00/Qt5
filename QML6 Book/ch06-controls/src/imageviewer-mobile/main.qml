import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Qt.labs.platform as Platform

ApplicationWindow {
    

    id: window

    visible: true
    width: 360
    height: 520
    title: qsTr("Image Viewer")

    background: Rectangle {
        color: "darkGray"
    }

    // Side panel that can be opened and closed using a swipe gesture.
    Drawer {
        id: drawer

        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height

        ListView {
            focus: true
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.text
                highlighted: ListView.isCurrentItem
                onClicked: {
                    drawer.close()
                    model.triggered()
                }
            }

            model: ListModel {
                ListElement {
                    text: qsTr("Open...")
                    triggered: function(){ fileOpenDialog.open(); }
                }
                ListElement {
                    text: qsTr("About...")
                    triggered: function(){ aboutDialog.open(); }
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
                ListElement {
                    text: qsTr("Test ")
                }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
    
    header: ToolBar {
        Material.background: Material.Orange

        ToolButton {
            id: menuButton
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            icon.source: "qrc:///images/baseline-menu-24px.svg"
            onClicked: drawer.open()
        }
        Label {
            anchors.centerIn: parent
            text: "Image Viewer"
            font.pixelSize: 20
            elide: Label.ElideRight
        }
    }

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        asynchronous: true
    }

    footer: Rectangle   {
        width: parent.width; height: 20
        anchors.top: image.bottom
        color: "orange"
        Flow {
            Label {
                text: qsTr("Image: " + image.source)
            }
        }
    }

    Platform.FileDialog {
        id: fileOpenDialog
        title: "Select an image file"
        folder: Platform.StandardPaths.writableLocation(Platform.StandardPaths.DocumentsLocation)
        nameFilters: [
            "Image files (*.png *.jpeg *.jpg)",
        ]
        onAccepted: {
            image.source = fileOpenDialog.file
        }
    }

    Dialog {
        id: aboutDialog
        title: qsTr("About")
        Label {
            anchors.fill: parent
            text: qsTr("QML Image Viewer\nA part of the QmlBook\nhttp://qmlbook.org")
            horizontalAlignment: Text.AlignHCenter
        }

        standardButtons: Dialog.Ok
    }
}
