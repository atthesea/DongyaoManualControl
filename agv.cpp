#include "agv.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostInfo>

#include "global.h"
#include "tcpclient.h"

Agv::Agv(AgvInfo *_agvinfo, QObject *parent) : QObject(parent),
    agvinfo(*_agvinfo)
{
    TcpClient *tcpclient = new TcpClient;
    tcpclient->moveToThread(&socketThread);
    connect(&socketThread, &QThread::finished, tcpclient, &QObject::deleteLater);
    connect(this, &Agv::sig_sendToHost, tcpclient, &TcpClient::slot_send);
    connect(this, &Agv::sig_connectToHost, tcpclient, &TcpClient::slot_connectToServer);
    connect(tcpclient, &TcpClient::sig_connect, this, &Agv::sig_connect);
    connect(tcpclient, &TcpClient::sig_disconnect, this, &Agv::sig_disconnect);
    connect(tcpclient, &TcpClient::sig_read, this, &Agv::slot_onRead);
    socketThread.start();
}

Agv::~Agv()
{
    socketThread.quit();
    socketThread.wait();
}

void Agv::send(QByteArray qba)
{
    emit sig_sendToHost(qba);
}

void Agv::connToServer()
{
    timer.setInterval(50);
    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_timeToSend()));
    emit sig_connectToHost(agvinfo.ip(),agvinfo.port());
    timer.start();
}

void Agv::slot_onRead(QByteArray qba)
{
    //TODO:
}

void Agv::slot_timeToSend()
{
    //是否是當前選中的那輛車
    if(agvinfo.name() == selectAgvName){
        //TODO:
        QByteArray qba;
        //组织数据



        emit send()
    }
}
