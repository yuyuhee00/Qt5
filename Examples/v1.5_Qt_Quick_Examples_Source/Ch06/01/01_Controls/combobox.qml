import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300
    height: 100
    visible: true

    ComboBox {
        anchors.centerIn: parent

        editable: true
        model: ListModel {
            id: model
            ListElement { text: "Banana"; color: "Yellow" }
            ListElement { text: "Apple"; color: "Green" }
            ListElement { text: "Coconut"; color: "Brown" }
        }
        onAccepted: {
            // 동일한 이름의 아이템이 없을 때만 추가
            if (find(currentText) === -1) {
                model.append({text: editText})
                currentIndex = find(editText)
            }
        }
    }
}
