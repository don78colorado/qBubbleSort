QT -= gui
QT += testlib
CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    test/mergesorttest.cpp

HEADERS += \
    bubblesort.h \
    bubblesorttest.h
