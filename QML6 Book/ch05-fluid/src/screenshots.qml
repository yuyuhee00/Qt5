import QtQuick
import QtQuick.Controls

Item {
    id: root

    ListModel {
        id: sourcesModel
        ListElement { source: "easing/EasingCurves.qml"; name: "easingcurves.png"; margin: 0; }
   }

    property int p: 0
    property string assetsource: ""
    property string assetname: ""
    property int shootmargin: 0

    Rectangle {
        anchors.fill: parent
        anchors.rightMargin: 1
        anchors.bottomMargin: 1

        border.color: "lightGray"
        border.width: 1

        Loader {
            id: loader

            x: 1; y: 1

            focus: true

            onLoaded: {
                if (loader.source != "") {
                    if (root.assetsource.indexOf("ss-") == -1) {
                        root.setSize(loader.item.width, loader.item.height)
                        root.shoot()
                    }
                }
            }
        }
    }

    function setSize(w,h)
    {
        loader.x = shootmargin
        loader.y = shootmargin
        root.width = w + 2 + shootmargin * 2
        root.height = h + 2 + shootmargin * 2
    }

    function shoot()
    {
        shootDelay.start()
    }

    function shootWithDelay(d)
    {
        shootDelay.interval = d
        root.shoot()
    }

    Timer {
        id: shootDelay
        interval: 100
        repeat: false
        onTriggered: root.takeScreenshot()
    }

    Component.onCompleted: {
        root.prepareScreenshot()
    }

    function prepareScreenshot()
    {
        shootDelay.interval = 100
        console.log("SS: " + p)
        assetsource = sourcesModel.get(p).source
        assetname = "../assets/automatic/" + sourcesModel.get(p).name
        shootmargin = sourcesModel.get(p).margin
        p += 1
        loader.source = assetsource
        console.log("    " + assetname)
        console.log("    " + loader.source)
    }

    function takeScreenshot()
    {
        console.log("TS: " + assetname)

        shorty.shootFull(assetname)
        if (p < sourcesModel.count)
        {
            loader.source = ""
            root.prepareScreenshot()
        }
        else {
            Qt.quit()
        }
    }
}
