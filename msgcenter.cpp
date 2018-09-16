#include "msgcenter.h"
#include "msgcenter.h"
#include <assert.h>
#include "global.h"
#include <iostream>
#include "protocol.h"

MsgCenter::MsgCenter(QObject *parent) : QObject(parent),
    agvconnection(nullptr),
    currentSelectIndex(0)
{

}

MsgCenter::~MsgCenter()
{
    if(agvconnection)delete agvconnection;
}

void MsgCenter::selectAgvChanged(int index)
{
    agv1info->setStatus(0);
    agv2info->setStatus(0);
    agv3info->setStatus(0);
    currentSelectIndex = index;
    if(index == 0){
        agvconnection->connectToServer(agv1info->ip(),agv1info->port());
    }else if(index == 1){
        agvconnection->connectToServer(agv2info->ip(),agv2info->port());
    }else if(index == 2){
        agvconnection->connectToServer(agv3info->ip(),agv3info->port());
    }
}

void MsgCenter::init()
{
    agvconnection = new AgvConnection();

    connect(agvconnection,SIGNAL(sig_connect()),this,SLOT(slot_connect()));
    connect(agvconnection,SIGNAL(sig_disconnect()),this,SLOT(slot_disconnect()));

    agvconnection->connectToServer(agv1info->ip(),agv1info->port());
    agvconnection->start();
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

void MsgCenter::setSpeed(int sp)
{
    g_speed = sp;
}
void MsgCenter::setTurn(int tn)
{
    g_turn = tn;
}

void MsgCenter::slot_connect()
{

    if(currentSelectIndex == 0){
        agv1info->setStatus(1);
    }else if(currentSelectIndex == 1){
        agv2info->setStatus(1);
    }else if(currentSelectIndex == 2){
        agv3info->setStatus(1);
    }
}

void MsgCenter::slot_disconnect()
{
    if(currentSelectIndex == 0){
        agv1info->setStatus(0);
    }else if(currentSelectIndex == 1){
        agv2info->setStatus(0);
    }else if(currentSelectIndex == 2){
        agv3info->setStatus(0);
    }
}
