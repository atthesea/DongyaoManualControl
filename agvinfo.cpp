#include "agvinfo.h"

AgvInfo::AgvInfo(QObject *parent) : QObject(parent),
    m_name(""),
    m_ip(""),
    m_status(0),
    m_port(9999)
{

}
