#ifndef MSGCENTER_H
#define MSGCENTER_H
#include <thread>
#include <QObject>
#include <QMap>

#include <QString>
#include <QString>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
//#include "agv.h"
#include "agvconnection.h"

//AGV基本信息
typedef struct _AGV_BASE_INFO
{
    QString name;
    QString ip;
    int port;
}AGV_BASE_INFO;


class MsgCenter : public QObject
{
    Q_OBJECT
public:
    explicit MsgCenter(QObject *parent = nullptr);

    ~MsgCenter();

    Q_INVOKABLE void init();

    Q_INVOKABLE void setFlagBz(bool _bz);
    Q_INVOKABLE void setFlagSpeed(bool _speed);
    Q_INVOKABLE void setFlagLift(bool _lift);

    Q_INVOKABLE void setSpeed(int sp);
    Q_INVOKABLE void setTurn(int tn);

    Q_INVOKABLE void selectAgvChanged(int index);
signals:

public slots:
    void slot_connect();
    void slot_disconnect();
private slots:

private:
    AgvConnection *agvconnection;
    int currentSelectIndex;
};

#endif // MSGCENTER_H
