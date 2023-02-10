import QtQuick 2.12

ListView {
    width: 100; height: 100

    model: MyModel
    delegate: Rectangle
    {
        height: 25
        width: 100
        Text { text: modelData }
    }
}
