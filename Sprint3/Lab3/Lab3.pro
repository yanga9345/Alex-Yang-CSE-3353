TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    search.cpp \
    node.cpp \
    path.cpp

HEADERS += \
    algorithm.h \
    fileio.h \
    node.h \
    search.h \
    searchalgo.h \
    path.h
