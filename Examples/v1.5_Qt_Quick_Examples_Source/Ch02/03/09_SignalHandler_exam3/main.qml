import QtQuick 2.12
import QtQuick.Window 2.12
import "content"

Window {
    visible: true; width: 360; height: 360
    SquareButton
    {
        width: 360; height: 360
        onActivated: console.log("Activated at " + xPosition + "," + yPosition)
        onDeactivated: console.log("Deactivated!")
    }
}
