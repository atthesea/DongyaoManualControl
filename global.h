#ifndef GLOBAL_H
#define GLOBAL_H

//全局变量
#include <QList>
#include <QObject>

#include "config.h"
#include "msgcenter.h"
#include "protocol.h"

extern Config g_config;
extern MsgCenter msgCenter;

extern bool g_flag_bz;
extern bool g_flag_speed;
extern bool g_flag_lift;
extern int g_speed;
extern int g_turn;

extern AgvInfo *agv1info;
extern AgvInfo *agv2info;
extern AgvInfo *agv3info;

extern QString selectAgvName;
//全局函数

//非阻塞的sleep[只阻塞当前线程] 最小单位是10ms
void QyhSleep(int msec);

int getRandom(int maxRandom);

#endif // GLOBAL_H
