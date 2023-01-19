import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300
    height: 200
    visible: true

    TextArea {
        anchors.centerIn: parent
        width: 280
        text:
          "[마가복음 12장 29절~31절] \n\n" +
          "29 예수께서 대답하셨다. \"첫째는 이것이다. 이스라엘아, 들어라." +
          "우리 하나님이신 주님은 오직 한 분이신 주님이시다.\n" +
          "30 네 마음을 다하고, 네 목숨을 다하고, 네 뜻을 다하고, 네 힘을" +
          " 다하여, 너의 하나님이신 주님을 사랑하여라.\" \n" +
          "31 둘째는 이것이다. \'네 이웃을 네 몸같이 사랑하여라.\' 이 계명" +
          " 보다 더 큰 계명은 없다."
    }
}
