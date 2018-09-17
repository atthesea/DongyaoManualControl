import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QyhCustomComponent 1.0
import "../common" as COMMON


Page {
    id:mainPage
    header: ToolBar{
        id:toolBar
        contentHeight:30

        COMMON.SettingsIcon {
            width: 28
            height: 28
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 10
            visible: false
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //window.showAdmin()
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

    Rectangle{
        id:rrr
        width: 0
        height: 0
        color: "red"
        anchors.centerIn: parent
    }

    Column {
        COMMON.QyhRadioWithStatusIndicator {
            id:agv1Radio

            text: "agv1"
            checked: true
            isConnect: agv1info.status === 1
            onCheckedChanged: {
                if(checked){
                    agv2Radio.checked = false
                    agv3Radio.checked = false
                    msgCenter.selectAgvChanged(0)
                }
            }
        }
        COMMON.QyhRadioWithStatusIndicator {
            id:agv2Radio
            text: "agv2"
            checked: false
            isConnect: agv2info.status === 1
            onCheckedChanged: {
                if(checked){
                    agv1Radio.checked = false
                    agv3Radio.checked = false
                    msgCenter.selectAgvChanged(1)
                }
            }
        }
        COMMON.QyhRadioWithStatusIndicator {
            id:agv3Radio
            text: "agv3"
            checked: false
            isConnect: agv3info.status === 1
            onCheckedChanged: {
                if(checked){
                    agv2Radio.checked = false
                    agv1Radio.checked = false
                    msgCenter.selectAgvChanged(2)
                }
            }
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
            msgCenter.setFlagSpeed(checked)
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
            msgCenter.setFlagLift(checked)
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
            if(!checked){
                speedCheckBox.checked = false
            }
            msgCenter.setFlagBz(checked)
        }
    }

    COMMON.QyhVSlider{
        titletext:"速度"
        id:speedSlider

        anchors.verticalCenter: rrr.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: rrr.x/2 - width/2

        from: -100
        value: 0
        to: 100
        stepSize: 1

        orientation:Qt.Vertical
        onValueChanged: {
            msgCenter.setSpeed(value);
        }
    }

    COMMON.QyhHSlider{
        titletext:"转向"
        id:turnSlider

        anchors.verticalCenter: rrr.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 130

        from: 100
        value: 0
        to: -100
        stepSize: -1
        orientation:Qt.Horizontal
        onValueChanged: {
            msgCenter.setTurn(value)
        }
    }

    function init()
    {

    }

}
