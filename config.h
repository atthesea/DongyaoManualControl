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
    QList<QObject *> getAgvInfos();
    void setAgvInfos(QList<QObject *> infos);
signals:
    void loadSuccess();
    void loadFail();

    void saveSuccess();
    void saveFail();
public slots:

private:
    QList<QObject *> agv_infos;
    QJsonObject params;
};

#endif // CONFIG_H
