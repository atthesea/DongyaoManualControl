#ifndef AGVINFO_H
#define AGVINFO_H

#include <QObject>

//model data!

class AgvInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString ip READ ip WRITE setIp NOTIFY ipChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(int status READ status WRITE setStatus NOTIFY statusChanged)

public:

    explicit AgvInfo(QObject *parent = nullptr);

    AgvInfo(const AgvInfo &b){
        setName(b.m_name);
        setIp(b.m_ip);
        setPort(b.m_port);
        setStatus(b.m_status);
    }

    AgvInfo &operator =(const AgvInfo &b){
        AgvInfo a;
        a.setName(b.m_name);
        a.setIp(b.m_ip);
        a.setPort(b.m_port);
        a.setStatus(b.m_status);
        return a;
    }

    QString name(){return m_name;}
    QString ip(){return m_ip;}
    int port(){return m_port;}
    int status(){return m_status;}

    void setName(QString _name){m_name=_name;emit nameChanged(_name);}
    void setIp(QString _ip){m_ip=_ip;emit ipChanged(_ip);}
    void setPort(int _port){m_port=_port;emit portChanged(_port);}
    void setStatus(int _status){m_status = _status;emit statusChanged(_status);}
signals:
    void nameChanged(QString);
    void ipChanged(QString);
    void portChanged(int);
    void statusChanged(int);
public slots:

private:
    QString m_name;
    QString m_ip;
    int m_port;
    int m_status;//0 未连接   1 已连接
};

#endif // AGVINFO_H
