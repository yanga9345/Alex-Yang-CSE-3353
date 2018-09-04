TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sort.cpp \
    bubble.cpp \
    merge.cpp \
    insertion.cpp \
    tree.cpp

HEADERS += \
    algorithm.h \
    sort.h \
    bubble.h \
    merge.h \
    insertion.h \
    sortalgo.h \
    tree.h \
    filegenerator.h
