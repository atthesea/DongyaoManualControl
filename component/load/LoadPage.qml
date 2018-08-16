import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import "../common" as COMMON


Page {
    id:loadpageTemp

    AnimatedImage {
        id: animated;
        source: "qrc:/gif/loading.gif";
        anchors.centerIn: parent
    }

    Text {
        id: name
        font.pixelSize: 24
        font.bold: true
        text: qsTr("LOADING config...")
        anchors.horizontalCenter: animated.horizontalCenter
        anchors.top: animated.bottom
    }

    Component.onCompleted: {
        g_config.load()
    }

    Connections{
        target: g_config
        onLoadFail:{
            name.text = qsTr("load config fail!!!!")
        }
        onLoadSuccess:{
            name.text = qsTr("connect to dispatch server...")
            msgCenter.init();

            name.text = qsTr("finish ...")
            window.showMain();
        }
    }
}
