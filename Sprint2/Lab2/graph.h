#ifndef GRAPH_H
#define GRAPH_H
// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include<iostream>
#include<list>
#include "dlinkedlist.h"
using namespace std;

// based on: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    DLinkedList<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph();
    Graph(int V);   // Constructor

    void setV(int v);

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
#endif // GRAPH_H
