import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Controls 1.4
import QyhCustomComponent 1.0

Page {
    //三个配置，一个确认 一个取消按钮
    GridLayout{
        anchors.centerIn: parent
        columns: 2

        Text {
            text: qsTr("AGV1 NAME:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv1_name_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV1 IP:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv1_ip_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV1 PORT:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv1_port_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }

        Text {
            text: qsTr("AGV2 NAME:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv2_name_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV2 IP:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv2_ip_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV2 PORT:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv2_port_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }


        Text {
            text: qsTr("AGV3 NAME:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv3_name_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV3 IP:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv3_ip_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }
        Text {
            text: qsTr("AGV3 PORT:")
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
        }
        TextField{
            id:agv3_port_input
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }

        Button{
            Layout.alignment: Qt.AlignVCenter|Qt.AlignRight
            text: "OK"
            onClicked: {
                g_config.setAgv1Info(agv1_name_input.text,agv1_ip_input.text,parseInt( agv1_port_input.text),0);
                g_config.setAgv2Info(agv2_name_input.text,agv2_ip_input.text,parseInt( agv2_port_input.text),0);
                g_config.setAgv3Info(agv3_name_input.text,agv3_ip_input.text,parseInt( agv3_port_input.text),0);
                g_config.save();
                window.showToast(qsTr("请重启程序，使改变生效"));
            }
        }
        Button{
            text: "Cancel"
            onClicked: window.showMain()
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }

    }

    function init()
    {
        agv1_name_input.text = agv1info.name;
        agv2_name_input.text = agv2info.name;
        agv3_name_input.text = agv3info.name;

        agv1_ip_input.text = agv1info.ip;
        agv2_ip_input.text = agv2info.ip;
        agv3_ip_input.text = agv3info.ip;

        agv1_port_input.text = ""+agv1info.port;
        agv2_port_input.text = ""+agv2info.port;
        agv3_port_input.text = ""+agv3info.port;
    }
}
