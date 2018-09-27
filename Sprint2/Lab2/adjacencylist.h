#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <string>
#include <list>
#include "source.h"
#include "dest.h"
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
    adjacencylist(DLinkedList<Source>);
    adjacencylist& operator= (adjacencylist);

    Source& get(int);

    int locationOf(int);
    bool contains(int);
    int getSize();
    void print();

    void DFSIterative(int, int);
    void DFSRecursive(int, int);

    void BFSIterative(int, int);
    void BFSRecursive(int, int);

    void Dijkstra(int, int);

    void AStar(int, int);
};

#endif // ADJACENCYLIST_H
