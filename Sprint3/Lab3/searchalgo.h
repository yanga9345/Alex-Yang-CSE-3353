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

    static string Brute_Force(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> tempVec;
        float totalDistance;

        vector<int> IDs; //integer representation of my graph
        //vector<int> bestPath;

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


    static string Dynamic_Programming(vector<Node> &vec, vector<int> &bestPath, float &bestDistance,  vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> tempVec;
        bestDistance = INT8_MAX;

        float** matrix = new float*[vec.size()];
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            matrix[i] = new float[vec.size()];
        }

        for(unsigned int i = 0; i < vec.size(); i++)
        {
            for(unsigned int j = 0; j < vec.size(); j++)
            {
                matrix[i][j] = vec[i].getDistance(vec[j]);
            }
        }

        vector<int> IDs;

        for(unsigned int i = 0; i < vec.size(); i++)
        {
            IDs.push_back(i);
        }

        float totalDistance;

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

#endif // SEATCHALGO_H
