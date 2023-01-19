import QtQuick 2.12

Item {
    Item {
        focus: true
        Keys.onPressed: {
            console.log("Loaded captured:",
                        event.text);
            event.accepted = true;
        }
    }
}
