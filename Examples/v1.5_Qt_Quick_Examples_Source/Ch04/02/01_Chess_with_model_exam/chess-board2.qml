import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 445; height: 445; color: "brown"; visible: true

    Grid {
        x: 5; y: 5
        rows: 8; columns: 8; spacing: 5

        Repeater {
            model: parent.rows * parent.columns
            Rectangle {
                width: 50; height: 50
                color: {
                    var row = Math.floor(index / 8);
                    var column = index % 8
                    if ((row + column) % 2 == 1)
                        "black";
                    else
                        "white";
                }
            }
        }
    }

    Image {
        id: knight
        property int cx
        property int cy

        source: "./images/knight.png"

        x: 5 + 55 * cx
        y: 5 + 55 * cy
    }
}
