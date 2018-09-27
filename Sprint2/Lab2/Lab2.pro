TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    search.cpp \
    graph.cpp \
    dest.cpp \
    source.cpp \
    adjacencylist.cpp

HEADERS += \
    searchalgo.h \
    algorithm.h \
    search.h \
    avltree.h \
    graph.h \
    source.h \
    dest.h \
    adjacencylist.h \
    stack.h \
    node.h \
    dlinkedlist.h \
    fileio.h
