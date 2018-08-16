#include "config.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QDebug>

Config::Config(QObject *parent) : QObject(parent)
{
}

QList<QObject *> Config::getAgvInfos()
{
    return agv_infos;
}

void Config::setAgvInfos(QList<QObject *> infos)
{
    agv_infos = infos;
    QJsonArray aaa;

    foreach (auto a, agv_infos) {
        QJsonObject obj;
        auto ai = static_cast<AgvInfo *>(a);
        obj["name"] = ai->name();
        obj["ip"] = ai->ip();
        obj["port"] = ai->port();
        aaa.append(obj);
    }


    params["agv_infos"] = aaa;
}

void Config::load()
{
#ifdef Q_OS_ANDROID
    //获取
    QString path = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
    QFile file(path + "/agv_client_config.json");
    //如果文件不存在，将assets下的config.json复制到该目录下
    //if(!file.exists()){
    QFile asseetsConfigFile("assets:/agv_client_config.json");
    if(!asseetsConfigFile.open(QIODevice::ReadOnly)){
        emit loadFail();
        return ;
    }
    QByteArray vala = asseetsConfigFile.readAll();
    qDebug()<<"vala length = "<<vala.length();
    qDebug()<<"vala = "<<QString::fromUtf8(vala);
    asseetsConfigFile.close();
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        emit loadFail();
        return ;
    }
    file.write(vala);
    file.close();
    //}
#else
    QFile file( "agv_client_config.json" );
#endif
    if(!file.open(QIODevice::ReadOnly)){
        emit loadFail();
        return ;
    }
    QByteArray val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val);
    params = d.object();

    QJsonArray agvs = params["agv_infos"].toArray();

    foreach (auto a, agvs) {
        AgvInfo *ai = new AgvInfo;
        ai->setName(a["name"].toString());
        ai->setIp(a["ip"].toString());
        ai->setPort(a["port"].toInt());
        agv_infos.append(ai);
    }

    emit loadSuccess();
}

void Config::save()
{
    QJsonDocument saveDoc(params);
#ifdef Q_OS_ANDROID
    QString path = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
    QFile saveFile(path + "/agv_client_config.json");
#else
    QFile saveFile( "agv_client_config.json" );
#endif
    if(!saveFile.open(QIODevice::WriteOnly)){
        emit saveFail();
        return ;
    }
    saveFile.write(saveDoc.toJson());
    saveFile.close();
    emit saveSuccess();
}


