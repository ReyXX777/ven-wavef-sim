QT += core gui quick widgets
CONFIG += c++17 release
TARGET = VentilatorWaveformSim
TEMPLATE = app

DEFINES += QT_NO_OPENGL

INCLUDEPATH += $$PWD/src/model $$PWD/src/controller

SOURCES += \
    main.cpp \
    src/model/Wm.cpp \
    src/model/Wp.cpp \
    src/controller/Sc.cpp

HEADERS += \
    src/model/Wm.h \
    src/model/Wp.h \
    src/controller/Sc.h

RESOURCES += resources.qrc

DESTDIR = $$PWD/build/release
OBJECTS_DIR = $$PWD/build/.obj
MOC_DIR = $$PWD/build/.moc
RCC_DIR = $$PWD/build/.rcc