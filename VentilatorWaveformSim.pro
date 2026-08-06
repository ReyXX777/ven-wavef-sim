QT += core gui quick widgets
CONFIG += c++17 release
TARGET = VentilatorWaveformSim
TEMPLATE = app

DEFINES += QT_NO_OPENGL

INCLUDEPATH += $$PWD/src/model $$PWD/src/controller

SOURCES += \
    main.cpp \
    src/model/WaveformModel.cpp \
    src/model/WaveformImageProvider.cpp \
    src/controller/SimController.cpp

HEADERS += \
    src/model/WaveformModel.h \
    src/model/WaveformImageProvider.h \
    src/controller/SimController.h

RESOURCES += resources.qrc

DESTDIR = $$PWD/build/release
OBJECTS_DIR = $$PWD/build/.obj
MOC_DIR = $$PWD/build/.moc
RCC_DIR = $$PWD/build/.rcc