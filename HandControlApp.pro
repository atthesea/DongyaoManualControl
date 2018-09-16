QT += quick websockets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    config.cpp \
    global.cpp \
    msgcenter.cpp \
    tcpclient.cpp \
    agvinfo.cpp \
    agvconnection.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    config.h \
    global.h \
    msgcenter.h \
    tcpclient.h \
    agvinfo.h \
    agvconnection.h


# assuming you want to deploy qml/foo/main.qml file, you need to add the flowing lines to your .pro/.pri file(s)
deployment.files=agv_client_config.json
android { #define an android block
    deployment.path=/assets/ #all assets must go to "/assets" folder of your android package
} else : maemo5 { #other platforms
    deployment.path=/opt/$${TARGET}
}
INSTALLS += deployment

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/res/values/apptheme.xml \
    android/res/drawable/splash.xml \
    android/res/drawable/hrg.png \
    agv_client_config.json

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
