#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include "agvinfo.h"

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

    Q_INVOKABLE void load();
    Q_INVOKABLE void save();

    Q_INVOKABLE void setAgv1Info(QString name,QString ip,int port,int status);
    Q_INVOKABLE void setAgv2Info(QString name, QString ip, int port, int status);
    Q_INVOKABLE void setAgv3Info(QString name,QString ip,int port,int status);

signals:
    void loadSuccess();
    void loadFail();

    void saveSuccess();
    void saveFail();
public slots:

private:
    QJsonObject params;
};

#endif // CONFIG_H
