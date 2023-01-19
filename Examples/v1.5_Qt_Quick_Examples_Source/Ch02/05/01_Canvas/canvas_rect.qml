import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 120
    height: 120

    Canvas {
        id: root
        width: 120; height: 120
        onPaint: {
            var ctx = getContext("2d")
            ctx.fillStyle = 'green'
            ctx.strokeStyle = "blue"
            ctx.lineWidth = 4

            // green 컬러로 내부를 칠하는 사각형 Drawing
            ctx.fillRect(20, 20, 80, 80)

            // 지정한 영역을 Cleare
            ctx.clearRect(30,30, 60, 60)

            // 팬을 이용해 내부가 칠하지 않은 사각형 그리기
            ctx.strokeRect(20,20, 40, 40)
        }
    }
}

