TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    search.cpp \
    graph.cpp

HEADERS += \
    searchalgo.h \
    algorithm.h \
    search.h \
    avltree.h \
    graph.h
