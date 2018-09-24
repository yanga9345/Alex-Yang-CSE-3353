#include "graph.h"

Graph::Graph(int vertices)
{
    vCount = vertices;
    adjacencyList = new std::list<int>[vCount];
}

void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}
