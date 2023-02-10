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
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        var x = index % 8;
                        var y = Math.floor(index/8);

                        console.log("x, y :" + x + "," + y);

                        // Knight 가 앞으로 두칸 옆으로 한 일 때 x,y = 2, 1
                        // 또는 Knight 가 옆으로 한칸 앞으로 컨 일때 x,y = 1, 2
                        console.log(Math.abs(x - knight.cx) + "," +
                                    Math.abs(y - knight.cy)
                                    )
                        if ((Math.abs(x - knight.cx) == 1 &&
                             Math.abs(y - knight.cy) == 2) ||
                            (Math.abs(x - knight.cx) == 2 &&
                             Math.abs(y - knight.cy) == 1)) {

                            knight.cx = x;
                            knight.cy = y;
                        }
                    }
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
