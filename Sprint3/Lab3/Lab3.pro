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
    node.h \
    search.h \
    filehandler.h \
    TSP_Algo.h
