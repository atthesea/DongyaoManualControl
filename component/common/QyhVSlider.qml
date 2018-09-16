import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Window 2.11

Slider {
    id: control
    value: 0
    property string titletext: ""

    background: Rectangle {
        x: control.leftPadding + control.availableWidth / 2 - width / 2
        y: control.topPadding
        implicitWidth: 4
        implicitHeight: Screen.width/4
        width: implicitWidth
        height: control.availableHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
            width: parent.width
            height:  control.visualPosition * parent.height
            color: "#21be2b"
            radius: 2
        }

        Text {
            text: ""+control.to
            anchors.bottom:parent.top
            anchors.left: parent.right
            anchors.leftMargin: 20
        }

        Text {
            text: ""+control.from
            anchors.top:parent.bottom
            anchors.left: parent.right
            anchors.leftMargin: 20
        }

        Text {
            text: ""+(control.to+control.from)/2
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.right
            anchors.leftMargin: 20
        }

        Text {
            text: control.titletext
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: 30
        }
    }

    handle: Rectangle {
        y: control.topPadding + control.visualPosition * (control.availableHeight - height)
        x: control.leftPadding  + control.availableWidth / 2 - width / 2
        implicitWidth: 26
        implicitHeight: 26
        radius: 13
        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"

        Text {
            text: ""+value
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.right: parent.right
            anchors.rightMargin: -20
            visible: pressed
        }
    }

    onPressedChanged: {
        if(pressed){
            ///console.log("p")
        }else{
            ///console.log("r")
            value = 0
        }
    }

    onMoved: {
        ///console.log("v="+value);
    }
}
