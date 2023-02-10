import QtQuick 2.4

Item {
    width: 200; height: 200

    Loader {
       id: myLoader
       anchors.centerIn: parent
       source: "page1.qml"
    }
}
