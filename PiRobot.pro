TEMPLATE = app
TARGET = PiRobotProgram

QT = core gui 3dcore 3drender 3dinput 3dlogic 3dextras

SOURCES += \
    main.cpp \
    window.cpp \
    robotview.cpp

HEADERS += \
    window.h \
    main.h \
    robotview.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

FORMS += \
    window.ui

RESOURCES += \
    robotmodel.qrc
