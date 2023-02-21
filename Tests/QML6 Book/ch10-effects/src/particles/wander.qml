import QtQuick
import QtQuick.Particles

Rectangle {
    id: root
    width: 480; height: 240
    color: "#1F1F1F"

    ParticleSystem {
        id: particleSystem
    }

    ImageParticle {
        source: "assets/particle.png"
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
        width: 1; height: 20
        system: particleSystem
        emitRate: 40
        lifeSpan: 6400
        lifeSpanVariation: 400
        size: 32
        velocity: AngleDirection {
            angle: 0
            angleVariation: 15
            magnitude: 100
            magnitudeVariation: 50
        }
    }

    // #region M1
    Wander {
        anchors.horizontalCenter: parent.horizontalCenter
        width: 240; height: 120
        system: particleSystem
        affectedParameter: Wander.Position
        pace: 200
        yVariance: 240
        Tracer {}
    }
    // #endregion M1
}
