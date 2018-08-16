#include "msgcenter.h"
#include "msgcenter.h"
#include <assert.h>
#include "global.h"
#include <iostream>
#include "protocol.h"

MsgCenter::MsgCenter(QObject *parent) : QObject(parent)
{

}
MsgCenter::~MsgCenter()
{

}
void MsgCenter::init()
{
    //根据配置文件，载入agv
    auto agv_infos = g_config.getAgvInfos();
    foreach (auto ai, agv_infos) {
        Agv *a = new Agv(static_cast<AgvInfo *>(ai));
        a->connToServer();
        agvs.push_back(a);
        connect(a,SIGNAL(sig_connect()),this,SLOT(slot_connect()));
        connect(a,SIGNAL(sig_disconnect()),this,SLOT(slot_disconnect()));
    }
}

QList<QObject *> MsgCenter::getAgvInfos()
{
    return g_config.getAgvInfos();
}
void MsgCenter::setAgvInfos(QList<QObject *> infos)
{
    g_config.setAgvInfos(infos);
}

void MsgCenter::setFlagBz(bool _bz)
{
    g_flag_bz = _bz;
}
void MsgCenter::setFlagSpeed(bool _speed)
{
    g_flag_speed = _speed;
}
void MsgCenter::setFlagLift(bool _lift)
{
    g_flag_lift = _lift;
}

//void MsgCenter::sendAgv(int index)
//{
//    if(index>agvs.length())return ;
//    auto a = agvs[index];
//    //a->send(qba);
//}


void MsgCenter::slot_connect()
{
    auto aa = static_cast<Agv *>(sender());
    for(int i=0;i<agvs.length();++i){
        if(agvs[i] == aa){
            emit sig_connect(i);
            break;
        }
    }
}

void MsgCenter::slot_disconnect()
{
    auto aa = static_cast<Agv *>(sender());
    for(int i=0;i<agvs.length();++i){
        if(agvs[i] == aa){
            emit sig_disconnect(i);
            break;
        }
    }
}
