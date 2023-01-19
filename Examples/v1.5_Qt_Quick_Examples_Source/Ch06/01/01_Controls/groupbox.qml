import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow
{
    width: 200
    height: 200
    visible: true

    GroupBox {
        anchors.centerIn: parent
        title: "Joining for?"

        Column {
            spacing: 10
            CheckBox { text: "Breakfast"; checked: true }
            CheckBox { text: "Lunch"; checked: false    }
            CheckBox { text: "Dinner"; checked: true    }
        }
    }
}
