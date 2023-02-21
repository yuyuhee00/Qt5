import QtQuick
import QtQuick.Particles

Rectangle {
    id: root
    width: 480; height: 160
    color: "#1f1f1f"

    ParticleSystem {
        id: particleSystem
    }

    Emitter {
        id: emitter
        anchors.centerIn: parent
        width: 160; height: 80
        system: particleSystem
        emitRate: 10                     //  particles emitted per second (defaults to 10 per second)
        lifeSpan: 1000                  // milliseconds the particle should last for (default to 1000 msec)
        lifeSpanVariation: 500      // lifespan variation between emitted particles
        size: 16
        endSize: 32
        Tracer { color: 'green' }
    }

    ImageParticle {
        source: "assets/particle.png"
        system: particleSystem
    }
}
