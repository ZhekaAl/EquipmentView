#-------------------------------------------------
#
# Project created by QtCreator 2017-07-04T17:44:16
#
#-------------------------------------------------

QT       += core gui sql
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EquipmentView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databaseinterface.cpp \
    custommodel.cpp

HEADERS  += mainwindow.h \
    databaseinterface.h \
    custommodel.h

FORMS += \
    mainwindow.ui
