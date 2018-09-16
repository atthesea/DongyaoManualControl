#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent),
    socket(nullptr)
{

}

void TcpClient::slot_connectToServer(QString _ip, int _port)
{
    if(socket == nullptr){
        socket = new QTcpSocket;
    }
    if(ip == _ip && port == _port && socket->isWritable())return ;
    if(socket->isWritable())socket->close();
    ip = _ip;
    port = _port;
    connect(socket,SIGNAL(connected()),this,SIGNAL(sig_connect()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(slot_readRead()));
    connect(socket,SIGNAL(disconnected()),this,SIGNAL(sig_disconnect()));
    socket->connectToHost(_ip,_port);
}

void TcpClient::slot_send(QByteArray qba)
{
    if(socket!=nullptr){
        qDebug()<<"qba.length ="<<qba.length();
        socket->write(qba);
        socket->flush();
    }
}

void TcpClient::slot_readRead()
{
    auto qba = socket->readAll();
    emit sig_read(qba);
}

void TcpClient::slot_disconnect()
{
    if(socket!=nullptr)
        socket->close();
}
