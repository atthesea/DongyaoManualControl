#include "global.h"
#include <QTime>
#include <QCoreApplication>

Config g_config;
MsgCenter msgCenter;


bool g_flag_bz = false;
bool g_flag_speed  = false;
bool g_flag_lift  = false;
int g_speed = 0;
int g_turn = 0;

AgvInfo *agv1info = new AgvInfo;
AgvInfo *agv2info = new AgvInfo;
AgvInfo *agv3info = new AgvInfo;

QString selectAgvName = "";

void QyhSleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}


int getRandom(int maxRandom)
{
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    if(maxRandom>0)
        return qrand()%maxRandom;
    return qrand();
}
