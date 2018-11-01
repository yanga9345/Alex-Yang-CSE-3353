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
#include <algorithm>

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
        int IDs[vec.size()/4];
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            IDs[i] = vec[i].getID();
        }
        Node currentNode = vec[0];
        while(std::next_permutation(IDs, IDs+vec.size()))
        {
            int size = sizeof(IDs);
            if(IDs[0] == source && IDs[sizeof(IDs)-1] == destination)
            {
                for(unsigned int i = 0; i < vec.size(); i++)
                {
                    cout << IDs[i] << " ";
                }
                cout << endl;
            }
        }
        return "Brute Force";
    }
};

#endif // SEATCHALGO_H
