QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SessionManager.cpp \
    loadfiledialog.cpp \
    main.cpp \
    mainwindow.cpp \
    maparea.cpp \
    obstacle.cpp \
    robot.cpp \
    robot_settings.cpp \
    obstacles.cpp \
    savefiledialog.cpp

HEADERS += \
    SessionManager.h \
    loadfiledialog.h \
    mainwindow.h \
    maparea.h \
    obstacle.h \
    robot.h \
    robot_settings.h \
    obstacles.h \
    savefiledialog.h

FORMS += \
    loadfiledialog.ui \
    mainwindow.ui \
    robot_settings.ui \
    obstacles.ui \
    savefiledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
