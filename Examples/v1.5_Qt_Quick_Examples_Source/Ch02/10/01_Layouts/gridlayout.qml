import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.2

ApplicationWindow {
    id: myWindow; width: 480; height: 320; visible: true

    GridLayout{
        columns: 3
        Button { text: "button 1"}
        Button { text: "button 2"}
        ColumnLayout{
            Label { text: "label 3A"}
            Label { text: "Label 3B"}
            Label { text: "label 3C"}
        }
        Button { text: "button 4"}
        Label{ text: "label 5"}
        Button { text: "button 6"}
        RowLayout{
            Button { text: "button 7A"}
            Button { text: "button 7B"}
        }
    }
}
