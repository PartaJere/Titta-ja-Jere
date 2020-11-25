TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    core/city.cc \
    core/engine.cc \
    core/statistics.cc \
    core/creategame.cc \
    graphics/busgraphics.cc \
    graphics/passengergraphics.cc \
    graphics/playergraphics.cc \
    graphics/restaurantgraphics.cc \
    graphics/stopgraphics.cc \
    windows/gameendedwindow.cc \
    windows/startwindow.cc \
    windows/mainwindow.cc \
    actors/player.cc \
    actors/restaurant.cc \
    main.cc


win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

HEADERS += \
    core/city.hh \
    core/engine.hh \
    core/statistics.hh \
    graphics/busgraphics.hh \
    graphics/graphicsobject.hh \
    graphics/passengergraphics.hh \
    graphics/playergraphics.hh \
    graphics/restaurantgraphics.hh \
    graphics/stopgraphics.hh \
    windows/gameendedwindow.hh \
    windows/mainwindow.hh \
    windows/startwindow.hh\
    actors/player.hh \
    actors/restaurant.hh




FORMS += \
    windows/gameendedwindow.ui \
    windows/startwindow.ui \
    windows/mainwindow.ui

RESOURCES += \
    images.qrc

DISTFILES +=

