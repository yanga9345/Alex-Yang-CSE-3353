#include "graph.h"

// from: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
Graph::Graph()
{

}

Graph::Graph(int V)
{
    this->V = V;
    //adj = new list<int>[V];
    adj = new DLinkedList<int>[V];
}

void Graph::addEdge(int v, int w)
{
    //adj[v].push_back(w); // Add w to v’s list.
    adj[v].add(w);
}


void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    //for (i = adj[v].begin(); i != adj[v].end(); ++i)
    for(int i = 0; i < adj->getSize();i++)
        if (!visited[i])
            DFSUtil(i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}
