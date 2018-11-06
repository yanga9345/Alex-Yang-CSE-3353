#ifndef TSP_ALGO_H
#define TSP_ALGO_H
#include <vector>
#include "node.h"
#include <iostream>

using namespace std;
//the reason my static sort algorithms return strings is because I want
//the names of the algorithms for algoName)

//templated TSP_Algo class containing all the algorithms (no .cpp)
#include <iostream>
#include <algorithm>

class TSP_Algo
{
public:
    TSP_Algo();

    //brute force algorithm
    static string Brute_Force(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> tempVec;
        float totalDistance;

        vector<int> IDs; //integer representation of my graph

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
                bestPath.clear();
                for(unsigned int j = 0; j < IDs.size(); j++)
                {
                    bestPath.push_back(IDs[j] + 1);
                }
            }

            tempVec.clear();
            for(unsigned int i = 0; i < vec.size(); i++)
            {
                tempVec.push_back(vec[IDs[i]].getID());
            }
            possiblePaths.push_back(tempVec);
            possibleDistances.push_back(totalDistance);

        } while(std::next_permutation(IDs.begin() + 1, IDs.end()));

        return "Brute Force";
    }


    //dynamic programming
    static string Dynamic_Programming(vector<Node> &vec, vector<int> &bestPath, float &bestDistance,  vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> tempVec;
        bestDistance = INT8_MAX;
        float totalDistance;

        //sets up an adjacency matrix
        float** matrix = new float*[vec.size()];
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            matrix[i] = new float[vec.size()];
        }

        //loads up the values of the matrix with the distances between the i and j nodes
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            for(unsigned int j = 0; j < vec.size(); j++)
            {
                matrix[i][j] = vec[i].getDistance(vec[j]);
            }
        }

        //vector of ints representing the ids of all the nodes
        vector<int> IDs;
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            IDs.push_back(i);
        }


        do
        {
            totalDistance = 0;

            for(unsigned int i = 1; i < IDs.size(); i++)
            {
                totalDistance += matrix[IDs[i-1]][IDs[i]];
            }

            totalDistance += matrix[0][IDs.size()-1];

            if(totalDistance < bestDistance)
            {
                bestDistance = totalDistance;
                bestPath.clear();
                for(unsigned int i = 0; i < vec.size(); i++)
                {
                    bestPath.push_back(vec[IDs[i]].getID());
                }
            }

            tempVec.clear();
            for(unsigned int i = 0; i < vec.size(); i++)
            {
                tempVec.push_back(vec[IDs[i]].getID());
            }
            possiblePaths.push_back(tempVec);
            possibleDistances.push_back(totalDistance);

        } while(std::next_permutation(IDs.begin() + 1, IDs.end()));

        return "Dynamic Programming";
    }
};

#endif // TSP_ALGO_H
