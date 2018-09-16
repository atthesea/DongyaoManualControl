import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4

Rectangle {
    width: 130
    height: 40
    id:control
    property string text: ""
    property bool checked: false
    property bool isConnect: false

    StatusIndicator{
        id:statusindicator
        color:"green"
        active: control.isConnect
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id:centertext
        text: control.text
        color: mousearea.pressed ? "#17a81a" : "#21be2b"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: statusindicator.right
        anchors.leftMargin: 10
    }

    Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: centertext.right
        anchors.leftMargin: 20
        width: 26
        height: 26
        radius: 13
        color: "transparent"
        border.color: mousearea.pressed ? "#17a81a" : "#21be2b"

        Rectangle {
            width: 14
            height: 14
            x: 6
            y: 6
            radius: 7
            color: mousearea.pressed ? "#17a81a" : "#21be2b"
            visible: control.checked
        }
    }

    MouseArea{
        anchors.fill: parent
        id:mousearea
        onClicked: {
            if(!control.checked)control.checked = true
        }
    }
}
