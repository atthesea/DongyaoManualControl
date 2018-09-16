#ifndef AGVCONNECTION_H
#define AGVCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QMutex>
#include "agvinfo.h"

class AgvConnection : public QThread
{
    Q_OBJECT
public:
    explicit AgvConnection(QObject *parent = nullptr);
    ~AgvConnection();

    void connectToServer(QString _ip,int _port);
    void run() override;
signals:
    void sig_connect();
    void sig_disconnect();
public slots:

private:
    QTcpSocket *socket;
    volatile bool quit;
    volatile bool needReconnect;

    QString ip;
    int port;
};

#endif // AGVCONNECTION_H
