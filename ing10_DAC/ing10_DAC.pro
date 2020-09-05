#-------------------------------------------------
#
# Project created by QtCreator 2020-01-01T20:47:08
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ing10_DAC
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/dac.cpp \
        src/baseserialcomm.cpp \
        src/mbserialmaster.cpp \
        src/protocoldialog.cpp

HEADERS += \
        inc/dac.h \
        inc/baseserialcomm.h \
        inc/mbserialmaster.h \
        inc/protocoldialog.h

FORMS += \
        ui/dac.ui \
        ui/protocoldialog.ui

RESOURCES += res/images.qrc

RC_ICONS = /res/general/ing10.ico

# 生成的ui.h所在路径
UI_DIR += ./ui
# 头文件路径
INCLUDEPATH +=  inc

# 配置输出路径: debug和release模式下的输出路径
# 配置动态链接库的路径: debug和release模式下的dll路径
CONFIG(debug, debug|release){
DESTDIR = ./exe                 # .exe 路径
#LIBS  += -L ../../debug -lSerialComm # .dll 路径
}else {
DESTDIR = ./exe
#LIBS  += -L ../../release -lSerialComm
}

# 预编译头文件
CONFIG += precompile_header
PRECOMPILED_HEADER += inc/dac.h \
                      inc/mbserialmaster.h \
                      inc/baseserialcomm.h

