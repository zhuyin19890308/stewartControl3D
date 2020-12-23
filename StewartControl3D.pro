QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
QT += 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation
QT += quickwidgets
CONFIG += resources_big

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calbackwardalgorithm.cpp \
    calculateposture.cpp \
    fsocket.cpp \
    main.cpp \
    mainwindow.cpp \
    mytcpclient.cpp \
    mytcpserver.cpp \
    myudp.cpp \
    scenemodifier.cpp \
    socketfactory.cpp

HEADERS += \
    calbackwardalgorithm.h \
    calculateposture.h \
    config.h \
    fsocket.h \
    gts.h \
    mainwindow.h \
    mytcpclient.h \
    mytcpserver.h \
    myudp.h \
    scenemodifier.h \
    socketfactory.h \
    structDefine.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/./ -lgts

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

RESOURCES +=

DISTFILES += \
    _3d.qml \
    _3dForm.ui.qml
