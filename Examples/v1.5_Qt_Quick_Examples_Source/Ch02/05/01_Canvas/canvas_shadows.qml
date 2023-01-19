import QtQuick 2.4

Canvas {
    id: root
    width: 200; height: 200

    onPaint: {
        var ctx = getContext("2d")

        ctx.strokeStyle = "#333"
        ctx.fillRect(0,0, root.width, root.height)

        ctx.shadowColor = "blue";
        ctx.shadowOffsetX = 2;
        ctx.shadowOffsetY = 2;

        //ctx.font = 'Bold 80px Ubuntu';
        ctx.font = 'Bold 80px'
        ctx.fillStyle = "#33a9ff";
        ctx.fillText("Earth",30,180);
    }
}
