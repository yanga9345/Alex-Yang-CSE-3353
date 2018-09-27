#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include "source.h"
#include "stack.h"
#include "dlinkedlist.h"

class Graph
{
    int vCount, edgeCount;
    //std::list<Source> *adjacencyList;
    std::vector<int> vertices;
    std::vector<int> edges;
    //std::vector<int> weights;
    Stack<int> stack;

    void DFSUtil(int v, bool visited[]);
public:
    Graph();
    Graph(int V);   // Constructor
    void addVertices(int);
    void addEdge(int, int);   // function to add a weighted edge to graph
    void DFS();    // prints DFS traversal of the complete graph
private:


};

#endif // GRAPH_H
