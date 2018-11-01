#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include <vector>
#include "node.h"
#include <iostream>

using namespace std;
//the reason my static sort algorithms return strings is because I want
//the names of the sorting method to be used in Sort (sortName)

//templated SortAlgo class containing all the algorithms (no .cpp)
#include <iostream>
#include <list>
//#include "adjacencylist.h"

class SearchAlgo
{
public:
    SearchAlgo();

    // The function to do DFS traversal. It uses recursive DFSUtil()
//    static string DFSRecursive(adjacencylist al, int source, int destination)
//    {
//        al.DFSRecursive(source, destination);
//        return "DFS Recursive";
//    }

    static string Brute_Force(vector<Node> vec, int source, int destination)
    {
        for(int i = 0; i < vec.size(); i++)
        {

        }
        return "Brute Force";
    }
};

#endif // SEATCHALGO_H
