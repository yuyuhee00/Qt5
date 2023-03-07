import QtQuick

// The root element is the Rectangle
Rectangle {
    // name this element root
    id: root

    // properties: <name>: <value>
    width: 120; height: 240

    // color property
    color: "#4A4A4A"

    // border property
//    border.width: 2
//    border.color: 'red'
    border {
        width: 2
        color: 'red'
    }

    // Declare a nested element (child of root)
    Image {
        id: triangle

        // reference the parent
        x: (parent.width - width)/2
        y: (parent.height - height)/2

        source: 'assets/triangle_red.png'
    }

    // Another child of root
    Text {
        // un-named element

        // reference element by id
        y: triangle.y + triangle.height + 20

        // reference root element
        width: root.width

        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: 'Triangle'
    }
}

