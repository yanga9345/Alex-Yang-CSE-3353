#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include <vector>
#include <iostream>

using namespace std;
//the reason my static sort algorithms return strings is because I want
//the names of the sorting method to be used in Sort (sortName)

//templated SortAlgo class containing all the algorithms (no .cpp)
#include <iostream>
#include <list>
#include "graph.h"
#include "adjacencylist.h"

class SearchAlgo
{
public:
    SearchAlgo();

//    static string DFSIterative(int source, int dest)
//    {

//        return "DFS Iterative";
//    }


//    void DFSUtil(int v, bool visited[])
//    {

//    }

    // The function to do DFS traversal. It uses recursive DFSUtil()
    static string DFSRecursive(DLinkedList<Source> sources, int source, int dest)
    {
        //g.DFS(source);
        return "DFS Recursive";
    }

//    static string BFSIterative(int source, int dest)
//    {
//        return "BFS Iterative";
//    }

//    static string BFSRecursive(int source, int dest)
//    {
//        return "BFS Recursive";
//    }

//    static string Dijkstra(int source, int dest)
//    {
//        return "Dijkstra";
//    }

//    static string AStar(int source, int dest)
//    {
//        return "A*";
//    }
};

#endif // SEATCHALGO_H
