#-------------------------------------------------
#
# Project created by QtCreator 2017-02-26T17:57:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimelineTest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    score.cpp \
    instrument.cpp \
    tempo.cpp \
    measurebox.cpp

HEADERS  += dialog.h \
    score.h \
    instrument.h \
    tempo.h \
    measurebox.h

FORMS    += dialog.ui
