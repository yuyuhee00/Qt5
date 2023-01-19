import QtQuick 2.12
import Shapes 1.0

Chart {
    width: 220; height: 200
    bars: [
        Bar { color: "#a00000"; value: -20 },
        Bar { color: "#00a000"; value: 50  },
        Bar { color: "#0000a0"; value: 100 },
        Bar { color: "#ff00a0"; value: 40  },
        Bar { color: "#00ffa0"; value: 70  }
    ]
}
