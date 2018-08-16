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
#include "agv.h"

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

    Q_INVOKABLE QList<QObject *> getAgvInfos();
    Q_INVOKABLE void setAgvInfos(QList<QObject *> infos);

    Q_INVOKABLE void setFlagBz(bool _bz);
    Q_INVOKABLE void setFlagSpeed(bool _speed);
    Q_INVOKABLE void setFlagLift(bool _lift);
signals:
    //连接状态改变
    void sig_connect(int);
    void sig_disconnect(int);

public slots:
    void slot_connect();
    void slot_disconnect();
private slots:

private:
    QList<Agv *> agvs;
};

#endif // MSGCENTER_H
