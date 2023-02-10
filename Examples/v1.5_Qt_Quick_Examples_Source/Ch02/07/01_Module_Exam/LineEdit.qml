import QtQuick 2.12

Rectangle
{
  border.color: "green";
  color: "white"; radius: 4; smooth: true

  TextInput {
    anchors.fill: parent
    anchors.margins: 2
    text: "Hello World."
    color: focus ? "black" : "lightgreen"
    font.pixelSize: parent.height - 4
  }
}
