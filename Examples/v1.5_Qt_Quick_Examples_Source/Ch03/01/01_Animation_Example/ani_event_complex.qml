import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 330; height: 230; visible: true

    Image {
        source: "images/qtlogo.png"
        x: 10; y: 20;
        id : logo

        NumberAnimation on scale
        {
            id : scaleAni
            from: 0.1; to: 1.0
            duration: 2000
            running: true

            onStarted : console.log("started")
            onStopped : console.log("stopped")
        }

        onScaleChanged: {
            if(scale > 0.5) {
                //scaleAni.stop()
                scaleAni.complete()

            }
            console.log("scale : " + scale);
        }
    }
}
