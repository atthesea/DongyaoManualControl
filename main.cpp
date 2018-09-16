#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "global.h"

int main(int argc, char *argv[])
{
    qApp->setOrganizationName("HRG");
    qApp->setApplicationName("AGV_CLIENT");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //AgvInfo
    qmlRegisterType<AgvInfo>( "QyhCustomComponent", 1, 0, "AgvInfo");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("g_config", &g_config);
    ctxt->setContextProperty("msgCenter", &msgCenter);
    ctxt->setContextProperty("agv1info", agv1info);
    ctxt->setContextProperty("agv2info", agv2info);
    ctxt->setContextProperty("agv3info", agv3info);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
