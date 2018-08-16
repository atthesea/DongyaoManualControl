#ifndef DISPATCHCONNECTION_H
#define DISPATCHCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>
#include "agvinfo.h"

class Agv : public QObject
{
    Q_OBJECT
public:
    explicit Agv(AgvInfo *_agvinfo,QObject *parent = nullptr);
    ~Agv();

    void connToServer();
    void send(QByteArray qba);
signals:
    //
    void sig_connectToHost(QString,int);
    void sig_sendToHost(QByteArray);

    //
    void sig_connect();
    void sig_disconnect();
public slots:
    void slot_onRead(QByteArray qba);
    void slot_timeToSend();
private:
    QThread socketThread;
    AgvInfo agvinfo;
    QTimer timer;
};

#endif // DISPATCHCONNECTION_H
