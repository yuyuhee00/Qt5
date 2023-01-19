import QtQuick 2.0


Rectangle {

    BorderImage {
        width: 180; height: 180
        border { left: 30; top: 30; right: 30; bottom: 30 }
        horizontalTileMode: BorderImage.Repeat
        verticalTileMode: BorderImage.Repeat
        source: "images/borderframe.png"
    }

}

//Window {
//    visible: true

//    Rectangle {
//        width: 180; height: 180

//        Image
//        {
//            source: "images/borderframe.png"
//        }

//    }


//    Rectangle {
//        width: 180; height: 180

//        BorderImage {

//            border {
//               left: 10; top: 10; right: 10; bottom: 10
//            }
//            horizontalTileMode: BorderImage.Stretch
//            verticalTileMode: BorderImage.Stretch
//            source: "images/borderframe.png"
//        }
//    }
//}
