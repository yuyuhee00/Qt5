import QtQuick 2.12
import QtQuick.Window 2.12
import "content" as MyContent

Window {
     visible: true; width: 250; height: 100; color: "lightblue"

     MyContent.NewCheckBox      {
          anchors.horizontalCenter: parent.horizontalCenter
          anchors.verticalCenter: parent.verticalCenter
     }
}
