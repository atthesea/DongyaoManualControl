import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Window 2.11

Slider {
    id: control
    value: 0
    property string titletext: ""
    width: 450
    background: Rectangle {
        x: control.leftPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: Screen.width/4
        implicitHeight: 4
        width: control.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            color: "#21be2b"
            radius: 2
        }

        Text {
            text: ""+control.from
            anchors.right:parent.left
            anchors.top: parent.bottom
            anchors.topMargin: 20
        }

        Text {
            text: ""+control.to
            anchors.left:parent.right
            anchors.top: parent.bottom
            anchors.topMargin: 20
        }

        Text {
            text: ""+(control.to+control.from)/2
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.bottom
            anchors.topMargin: 20
        }

        Text {
            text: control.titletext
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: 40
        }

    }

    handle: Rectangle {
        x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 60
        implicitHeight: 60
        radius: 30
        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"

        Text {
            text: ""+value
            anchors.verticalCenter: parent.verticalCenter
            anchors.top: parent.top
            anchors.topMargin: -20
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
