import QtQuick

Item {
    Item {
        focus: true
        Keys.onPressed: (event)=> {
            console.log("Loaded captured:",  event.text);
            event.accepted = true;
        }
    }
}
