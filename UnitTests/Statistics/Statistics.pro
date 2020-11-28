QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../../Course/CourseLib/interfaces/istatistics.hh\
           ../../Game/core/statistics.hh

SOURCES +=  tst_statistics.cpp\
            ../../Game/core/statistics.cc

DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += \
        ../../Course/CourseLib\
        ../../Game/


