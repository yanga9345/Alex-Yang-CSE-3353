#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <string>
#include <list>
#include "source.h"
#include "dest.h"
//#include "fileio.h"
#include "stack.h"

#include <iostream>

//contains the adjacency list used in flight planning
class adjacencylist
{
private:
    //private data members
    DLinkedList<Source> flights; //flights is a linked list of sources which each have their own linked list of destinations
    DLinkedList<int> its;
    int numSources;
public:
    //public functions
    adjacencylist();
    adjacencylist(char*);
    adjacencylist& operator= (adjacencylist);

    Source& get(int);

    int locationOf(int);
    bool contains(int);
    int getSize();
    void print();

};

#endif // ADJACENCYLIST_H
