#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>

class Graph
{
    int vCount;
    std::list<int> *adjacencyList;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int vertices, int w);   // function to add an edge to graph
    void DFS();    // prints DFS traversal of the complete graph
private:

};

#endif // GRAPH_H
