#include "global.h"
#include <QTime>
#include <QCoreApplication>

Config g_config;
MsgCenter msgCenter;


bool g_flag_bz = false;
bool g_flag_speed  = false;
bool g_flag_lift  = false;
QString selectAgvName = "";
void QyhSleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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
