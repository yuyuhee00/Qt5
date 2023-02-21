import QtQuick

Rectangle {
    width: 480; height: 240
    color: '#1e1e1e'

    Row {
        anchors.centerIn: parent
        spacing: 20
        Image {
            id: sourceImage
            width: 80; height: width
            source: '../assets/tulips.jpg'
        }

        ShaderEffect {
            id: effect
            width: 80; height: width
            property variant source: sourceImage
        }

        ShaderEffect {
            id: effect2
            width: 80; height: width
            property variant source: sourceImage

            vertexShader: "default.vert.qsb"
            fragmentShader: "default.frag.qsb"
        }
    }
}
