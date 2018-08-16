import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QyhCustomComponent 1.0
import "../common" as COMMON


Page {
    header: ToolBar{
        id:toolBar
        contentHeight:30

        COMMON.SettingsIcon {
            width: 28
            height: 28
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 10
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //TODO
                    window.showAdmin()
                }
            }
        }

        //两个链接状态的显示
        Text {
            id: name
            text: qsTr("MAIN")
            anchors.centerIn: parent
        }
    }

    ButtonGroup {
        id: buttonGroup
    }

    Rectangle{
        id:rrr
        width: 0
        height: 0
        color: "red"
        anchors.centerIn: parent
    }

    //TODO:
    ListView {
        id:agvSelect
        anchors.left: parent.left
        anchors.top: parent.top
        width: 100; height: 200

        model: msgCenter.getAgvInfos()
        delegate: COMMON.QyhRadioDelegate {
            text: modelData.name
            checked: index == 0
            isConnect: modelData.status === 1
            ButtonGroup.group: buttonGroup
        }
    }


    CheckBox{
        id:speedCheckBox
        anchors.top:parent.top
        anchors.topMargin: 15
        anchors.left: liftCheckBox.left
        anchors.leftMargin: -liftCheckBox.width-10
        text: qsTr("速度")
        checked: false
        onCheckStateChanged: {
            if(checked){
                bzCheckBox.checked = true
            }
        }
    }

    CheckBox{
        id:liftCheckBox
        anchors.top:parent.top
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 20
        text: qsTr("顶升")
        checked: false
        onCheckStateChanged: {
            if(checked){

            }
        }
    }

    CheckBox{
        id:bzCheckBox
        anchors.top:parent.top
        anchors.topMargin: 15
        anchors.left: speedCheckBox.left
        anchors.leftMargin: -speedCheckBox.width-10
        text: qsTr("抱闸")
        checked: false
        onCheckedChanged: {
            if(checked){

            }
        }
    }

    COMMON.QyhVSlider{
        titletext:"速度"
        id:speedSlider
        anchors.verticalCenter: rrr.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: rrr.x/2+30
        from: 100
        value: 0
        to: -100
        stepSize: 1
        orientation:Qt.Vertical
    }

    COMMON.QyhHSlider{
        titletext:"转向"
        id:turnSlider
        anchors.verticalCenter: rrr.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: rrr.x/2 - width/2
        from: 100
        value: 0
        to: -100
        stepSize: -1
        orientation:Qt.Horizontal
    }



}
