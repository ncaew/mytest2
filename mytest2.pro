#-------------------------------------------------
#
# Project created by QtCreator 2017-05-11T14:20:13
#
#-------------------------------------------------

QT       += core gui webkitwidgets network
#webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mytest2
TEMPLATE = app
CONFIG 	   += c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS       += -lVLCQtCore -lVLCQtWidgets

