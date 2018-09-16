#include "config.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QDebug>
#include "global.h"

Config::Config(QObject *parent) : QObject(parent)
{
}

void Config::setAgv1Info(QString name,QString ip,int port,int status)
{
    agv1info->setName(name);
    agv1info->setIp(ip);
    agv1info->setPort(port);
    agv1info->setStatus(status);
    QJsonObject obj;
    obj["name"] = name;
    obj["ip"] = ip;
    obj["port"] = port;
    params["agv1"] = obj;
}

void Config::setAgv2Info(QString name,QString ip,int port,int status)
{
    agv2info->setName(name);
    agv2info->setIp(ip);
    agv2info->setPort(port);
    agv2info->setStatus(status);
    QJsonObject obj;
    obj["name"] = name;
    obj["ip"] = ip;
    obj["port"] = port;
    params["agv2"] = obj;
}
void Config::setAgv3Info(QString name,QString ip,int port,int status)
{
    agv3info->setName(name);
    agv3info->setIp(ip);
    agv3info->setPort(port);
    agv3info->setStatus(status);
    QJsonObject obj;
    obj["name"] = name;
    obj["ip"] = ip;
    obj["port"] = port;
    params["agv3"] = obj;
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

    QJsonObject agv1obj = params["agv1"].toObject();


    if(agv1info == nullptr)agv1info = new AgvInfo;
    if(agv2info == nullptr)agv2info = new AgvInfo;
    if(agv3info == nullptr)agv3info = new AgvInfo;

    agv1info->setName(agv1obj["name"].toString());
    agv1info->setIp(agv1obj["ip"].toString());
    agv1info->setPort(agv1obj["port"].toInt());

    QJsonObject agv2obj = params["agv2"].toObject();
    agv2info->setName(agv2obj["name"].toString());
    agv2info->setIp(agv2obj["ip"].toString());
    agv2info->setPort(agv2obj["port"].toInt());

    QJsonObject agv3obj = params["agv3"].toObject();
    agv3info->setName(agv3obj["name"].toString());
    agv3info->setIp(agv3obj["ip"].toString());
    agv3info->setPort(agv3obj["port"].toInt());


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


