#include "graph.h"

Graph::Graph()
{
    vCount = 0;
    edgeCount = 0;
    vertices = {};
    edges = {};
    stack = {};
}

Graph::Graph(int v)
{
    vCount = v;
    edgeCount = 0;
    vertices = {};
    edges = {};
    stack = {};
    //adjacencyList = new std::list<Source>[vCount];
}

void Graph::addVertices(int v)
{
    vertices.push_back(v);
    //edges[v] = 0;
}

void Graph::addEdge(int v1, int v2)
{
    //adjacencyList[v1].push_back(v2);
    edges[v1] = v2;
}


