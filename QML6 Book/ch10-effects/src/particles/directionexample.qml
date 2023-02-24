import QtQuick 2.5
import QtQuick.Particles 2.0

Rectangle {
    id: root
    width: 480; height: 240
    color: "#1F1F1F"

    ParticleSystem {
        id: particleSystem
    }

    ImageParticle {
        source: "assets/star.png"
        system: particleSystem
        color: '#FFD700'
        colorVariation: 0.2
        rotation: 0
        rotationVariation: 45
        rotationVelocity: 15
        rotationVelocityVariation: 15
        entryEffect: ImageParticle.Scale
    }

    Emitter {
        id: emitter
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: 1; height: 1
        system: particleSystem
        emitRate: 10
        lifeSpan: 6400
        lifeSpanVariation: 400
        size: 32
        velocity: TargetDirection {
            targetItem: target1
            targetVariation: 20
            magnitude: 50
        }
        acceleration: TargetDirection {
            targetItem: target2
            targetVariation: 20
            magnitude: 50
        }
    }

    Rectangle {
        id: target1
        width: 40; height: width
        radius: width/2
        color: '#FF0000'
        opacity: 0.5

        MouseArea {
            anchors.fill: parent
            drag.target: target1
        }
    }

    Rectangle {
        id: target2
        width: 40; height: width
        radius: width/2
        color: '#00FF00'
        opacity: 0.5

        MouseArea {
            anchors.fill: parent
            drag.target: target2
        }
    }
}
