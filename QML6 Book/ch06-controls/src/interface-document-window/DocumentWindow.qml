import QtQuick
import QtQuick.Controls
import Qt.labs.platform as Platform

ApplicationWindow {
    id: root

    title: (fileName.length===0 ? qsTr("Document"):fileName) + (isDirty?"*":"")

    width: 640
    height: 480

    property bool isDirty: true        // Has the document got unsaved changes?
    property string fileName           // The filename of the document
    property bool tryingToClose: false // Is the window trying to close (but needs a file name first)?

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&New")
                icon.name: "document-new"
                onTriggered: root.newDocument()
            }
            MenuSeparator {}
            MenuItem {
                text: qsTr("&Open")
                icon.name: "document-open"
                onTriggered: openDocument()
            }
            MenuItem {
                text: qsTr("&Save")
                icon.name: "document-save"
                onTriggered: saveDocument()
            }
            MenuItem {
                text: qsTr("Save &As...")
                icon.name: "document-save-as"
                onTriggered: saveAsDocument()
            }
        }
    }

    function createNewDocument()
    {
        var component = Qt.createComponent("DocumentWindow.qml");
        var window = component.createObject();
        return window;
    }

    function newDocument()
    {
        var window = createNewDocument();
        window.show();
    }

    function openDocument(fileName)
    {
        openDialog.open();
    }

    function saveAsDocument()
    {
        saveAsDialog.open();
    }

    function saveDocument()
    {
        if (fileName.length === 0)
        {
            root.saveAsDocument();
        }
        else
        {
            // Save document here
            console.log("Saving document")
            root.isDirty = false;

            if (root.tryingToClose)
                root.close();
        }
    }

    Platform.FileDialog {
        id: openDialog
        title: "Open"
        folder: Platform.StandardPaths.writableLocation(Platform.StandardPaths.DocumentsLocation)
        onAccepted: {
            var window = root.createNewDocument();
            window.fileName = openDialog.file;
            window.show();
        }
    }

    Platform.FileDialog {
        id: saveAsDialog
        title: "Save As"
        folder: Platform.StandardPaths.writableLocation(Platform.StandardPaths.DocumentsLocation)
        onAccepted: {
            root.fileName = saveAsDialog.file
            saveDocument();
        }
        onRejected: {
            root.tryingToClose = false;
        }
    }

    onClosing: function(close) {
        if (root.isDirty) {
            closeWarningDialog.open();
            close.accepted = false;
        }
    }

    Platform.MessageDialog {
        id: closeWarningDialog
        title: "Closing document"
        text: "You have unsaved changed. Do you want to save your changes?"
        buttons: Platform.MessageDialog.Yes | Platform.MessageDialog.No | Platform.MessageDialog.Cancel
        onYesClicked: {
            // Attempt to save the document
            root.tryingToClose = true;
            root.saveDocument();
        }
        onNoClicked: {
            // Close the window
            root.isDirty = false;
            root.close()
        }
        onRejected: {
            // Do nothing, aborting the closing of the window
        }
    }
}
