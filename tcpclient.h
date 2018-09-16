#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
signals:
    void sig_connect();
    void sig_disconnect();
    void sig_read(QByteArray);
public slots:
    void slot_connectToServer(QString _ip,int _port);
    void slot_send(QByteArray qba);
    void slot_disconnect();
private slots:
    void slot_readRead();
private:
    QTcpSocket *socket;
    QString ip;
    int port;
};

#endif // TCPCLIENT_H
