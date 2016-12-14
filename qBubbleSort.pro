QT += core
QT -= gui

CONFIG += c++11 testlib

TARGET = qBubbleSort
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bubblesorttest.cpp

HEADERS += \
    bubblesort.h
