import QtQuick
import "content" as MyContent

Window {
     visible: true; width: 250; height: 100; color: "lightblue"

     MyContent.NewCheckBox      {
          anchors.horizontalCenter: parent.horizontalCenter
          anchors.verticalCenter: parent.verticalCenter

          onMyChecked: {
              console.log("Clicked...")
          }
     }
}
