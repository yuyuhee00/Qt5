import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width:200
    height: 200

    Canvas {
        id: root
        width: 200
        height: 200

        onPaint:
        {
            var ctx = getContext("2d")

            ctx.lineWidth = 4 // 그리는 팬의 Width
            ctx.strokeStyle = "blue" // 그리는 팬의 Color
            ctx.fillStyle = "steelblue" // 그리는 영역안에 채울 Color

            ctx.beginPath() // Path를 그리기 시작할 때 호출 (point 사이을 선으로 그릴때 사
            ctx.moveTo(50,50) // 시작점
            ctx.lineTo(150,50)
            ctx.lineTo(150,150)
            ctx.lineTo(50,150)
            ctx.closePath()  // Path 그리고 난 다음 end 호출

            ctx.fill()
            ctx.stroke()
        }
    }

}

