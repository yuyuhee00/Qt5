import QtQuick
import QtQuick.Controls
import "../common"

Background {
    width: 300
    height: 290

    ListModel {
        id: spaceMen

        ListElement { name: "Abdul Ahad Mohmand"; nation: "Afganistan"; }
        ListElement { name: "Marcos Pontes"; nation: "Brazil"; }
        ListElement { name: "Alexandar Panayotov Alexandrov"; nation: "Bulgaria"; }
        ListElement { name: "Georgi Ivanov"; nation: "Bulgaria"; }
        ListElement { name: "Roberta Bondar"; nation: "Canada"; }
        ListElement { name: "Marc Garneau"; nation: "Canada"; }
        ListElement { name: "Chris Hadfield"; nation: "Canada"; }
        ListElement { name: "Guy Laliberte"; nation: "Canada"; }
        ListElement { name: "Steven MacLean"; nation: "Canada"; }
        ListElement { name: "Julie Payette"; nation: "Canada"; }
        ListElement { name: "Robert Thirsk"; nation: "Canada"; }
        ListElement { name: "Bjarni Tryggvason"; nation: "Canada"; }
        ListElement { name: "Dafydd Williams"; nation: "Canada"; }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 20

        clip: true

        model: spaceMen
        delegate: spaceManDelegate

        //
        // Defines which property to use to divide the contents into sections.
        // - Model must be sorted so that each section consists of continuous elements,
        //   otherwise, the same property name might appear in multiple locations.
        //
        section.property: "nation"

        section.delegate: sectionDelegate
    }

    Component {
        id: spaceManDelegate

        Item {
            id: spaceManWrapper

            required property string name

            width: ListView.view.width
            height: 20

            Text {
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 8
                font.pixelSize: 12
                text: spaceManWrapper.name
                color: '#1f1f1f'
            }
        }
    }

    Component {
        id: sectionDelegate

        BlueBox {
            id: sectionWrapper

            required property string section

            width: ListView.view ? ListView.view.width : 0
            height: 20
            text: sectionWrapper.section
            fontColor: '#e0e0e0'
        }
    }
}
