import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

ApplicationWindow {
    width: 300; height: 100; visible: true

    ExclusiveGroup { id: exclusiveGroup1 }
    ExclusiveGroup { id: exclusiveGroup2 }

    Column{
        Column {
            CheckBox { text: "option 1"; exclusiveGroup: exclusiveGroup1 }
            CheckBox { text: "option 2"; exclusiveGroup: exclusiveGroup1 }
            CheckBox { text: "option 3"; exclusiveGroup: exclusiveGroup1 }
        }
        Row {
            spacing: 10
            CheckBox {
                text: "option A"; checked: true; exclusiveGroup: exclusiveGroup2
            }
            CheckBox {
                text: "option B"; exclusiveGroup: exclusiveGroup2
            }
            CheckBox {
                text: "option C"; exclusiveGroup: exclusiveGroup2
            }
        }
    }
}

