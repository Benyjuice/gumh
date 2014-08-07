#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T20:38:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gumh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogauth.cpp \
    editconfig.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    dialogauth.h \
    editconfig.h \
    form.h

FORMS    += mainwindow.ui \
    dialogauth.ui \
    editconfig.ui \
    form.ui

OTHER_FILES += \
               res/app_zh_CN.qm

TRANSLATIONS += app_zh-CN.ts

RESOURCES += \
    res.qrc
