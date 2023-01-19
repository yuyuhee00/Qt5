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
                    console.log("row, column : " + row + "," + column)

                    // 짝수면 1, 그렇지 않으면 0
                    if ((row + column) % 2 == 1)
                        "black";
                    else
                        "white";
                }
            }
        }
    }
}





