#-------------------------------------------------
#
# Project created by QtCreator 2019-02-14T15:53:14
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11

QT       += core

QT       -= gui

TARGET = testqprocess
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    testqprocess.cpp \
    processlauncher.cpp

HEADERS += \
    testqprocess.h \
    processlauncher.h
