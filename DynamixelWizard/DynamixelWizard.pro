#-------------------------------------------------
#
# Project created by QtCreator 2013-05-25T13:11:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DynamixelWizard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    servo.cpp \
    dynamixel.c \
    dxl_hal.c \
    data.cpp

HEADERS  += mainwindow.h \
    servo.h \
    dynamixel.h \
    dxl_hal.h \
    data.h

FORMS    += mainwindow.ui
