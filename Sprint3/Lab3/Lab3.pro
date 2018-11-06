TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    search.cpp \
    node.cpp \
    filehandler.cpp

HEADERS += \
    algorithm.h \
    fileio.h \
    node.h \
    search.h \
    searchalgo.h \
    filehandler.h
