TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    filehandler.cpp \
    node.cpp \
    search.cpp

HEADERS += \
    algorithm.h \
    filehandler.h \
    node.h \
    search.h \
    TSP_Algo.h
