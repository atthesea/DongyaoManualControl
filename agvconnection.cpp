#include "agvconnection.h"
#include <QByteArray>
#include "global.h"

const int PACKET_HEAD= 0x55 ;// 包头
const int PACKET_END = 0xAA;// 包尾

AgvConnection::AgvConnection(QObject *parent) : QThread(parent),
    socket(nullptr),
    quit(false),
    ip(""),
    port(8081),
    needReconnect(false)
{

}

AgvConnection::~AgvConnection()
{
    quit = true;
    wait();
}

void AgvConnection::connectToServer(QString _ip, int _port)
{
    ip = _ip;
    port = _port;
    needReconnect = true;
}

void AgvConnection::run()
{
    int mHeartCount = 1;

    socket = new QTcpSocket;
    connect(socket,SIGNAL(connected()),this,SIGNAL(sig_connect()));
    connect(socket,SIGNAL(disconnected()),this,SIGNAL(sig_disconnect()));

    while(!quit)
    {
        if(ip.length()<=0){
            QyhSleep(2000);
            continue;
        }

        needReconnect = false;
        socket->close();
        socket->connectToHost(ip,port);
        bool isconnected = false;
        while(!quit && !needReconnect){
            if(socket->state() == QAbstractSocket::ConnectedState){
                isconnected = true;
                break;
            }else if(socket->state() == QAbstractSocket::UnconnectedState ||socket->state() == QAbstractSocket::ClosingState)
            {
                isconnected = false;
                break;
            }
            QyhSleep(100);
        }

        if(!isconnected){
            QyhSleep(2000);
            continue;
        }

        if(needReconnect)continue;

        mHeartCount = 1;

        while(!quit && socket!=nullptr && socket->state() == QAbstractSocket::ConnectedState &&!needReconnect)
        {
            QByteArray qba;
            qba.append((char)PACKET_HEAD);// 帧头部
            qba.append((char)(0x08)); //数据长度， 固定8
            qba.append((char)1); // 设备ID
            qba.append((char)11); //命令类型
            int xx = 0;
            if(g_flag_bz)xx |= 0x01<<2;
            if(g_flag_speed)xx |= 0x01<<1;
            if(g_flag_lift)xx |= 0x01;

            qba.append((char)xx);
            qba.append((char)g_turn);
            qba.append((char)g_speed);

            mHeartCount = mHeartCount < 255 ? ++mHeartCount:1; //从1到255循环心跳计数
            qba.append((char)mHeartCount);

            int crc8 = 0;
            for(int i=0;i<6;++i){
                crc8 += qba[i+2];
                crc8 &= 0xFF;
            }
            qba.append((char)crc8);
            qba.append((char)PACKET_END);// 帧尾部

            socket->write(qba);
            socket->flush();

            QyhSleep(200);
        }
    }
}
