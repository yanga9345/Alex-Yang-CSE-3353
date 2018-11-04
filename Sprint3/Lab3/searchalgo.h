#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include <vector>
#include "node.h"
#include "path.h"
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

    static string Brute_Force(vector<Node> vec)
    {

        float totalDistance;
        float bestDistance = INT8_MAX;

        vector<int> IDs; //integer representation of my graph
        vector<int> bestPath;

        //sets IDs to the IDs of each node of my graph
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            IDs.push_back(vec[i].getID() - 1);
        }

        //calculates the best path using brute force techniques
        do
        {
            totalDistance = 0;
            for(unsigned int i = 1; i < IDs.size(); i++)
            {
                totalDistance += vec[IDs[i-1]].getDistance(vec[IDs[i]]);
            }
            totalDistance += vec[0].getDistance(vec[vec.size()-1]);

            if(totalDistance < bestDistance)
            {
                bestDistance = totalDistance;
                //bestPath = IDs;
                for(unsigned int j = 0; j < IDs.size(); j++)
                {
                    bestPath.push_back(IDs[j] + 1);
                }
            }
        } while(std::next_permutation(IDs.begin() + 1, IDs.end()));

        //displays best path
        std::cout << "Best Path: ";
        for(unsigned int i = 0; i < bestPath.size(); i++)
        {
            std::cout << bestPath[i];
            if(i < bestPath.size() - 1)
            {
                std::cout << " -> ";
            }
        }
        std::cout << endl;
        std::cout << "Best Path Length: " << bestDistance << endl << endl;

        return "Brute Force";
    }
};

#endif // SEATCHALGO_H
