#ifndef TSP_ALGO_H
#define TSP_ALGO_H
#include <vector>
#include "node.h"
#include <iostream>
#include <math.h>

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

    static float getFitness(vector<int> IDs, vector<Node> vec)
    {
        float totalDistance = 0;
        for(unsigned int i = 0; i < IDs.size()-1; i++)
        {
            totalDistance += vec[IDs[i]-1].getDistance(vec[IDs[i+1]-1]);
        }
        totalDistance += vec[0].getDistance(vec[vec.size()-1]);
        return totalDistance;
    }

    static void crossover(vector<int> &p1, vector<int> p2, int crossRate)
    {
        int v1, temp1, temp2;
        for(unsigned int i = 0; i < crossRate; i++)
        {
            //generate number within a parent
            v1 = rand() % p1.size();
            //go to that location on each parent
            temp1 = p1[v1];
            temp2 = p2[v1];
            p1[v1] = p2[v1];
            p2[v1] = temp1;
            //swap the locations
            //search each parent and find out where the duplicates are and replace them with whatever was missing
            for(unsigned int j = 0; j < p1.size(); j++)
            {
                if(j != v1)
                {
                    if(p1[j] == temp2)
                    {
                        p1[j] = temp1;
                    }
                }
            }
        }
    }

    //mutates an optimal solution to swap two elements around
    static std::vector<int> generateNeighbor(vector<int> in)
    {
        int swap1, swap2, temp;
        swap1 = rand() % (in.size()-1) + 1;
        while(true)
        {
            swap2 = rand() % (in.size()-1) + 1;
            if(swap1 != swap2)
                break;
        }
        temp = in[swap1];
        in[swap1] = in[swap2];
        in[swap2] = temp;
        return in;
    }

    //Simulated Annealing
    static std::string SA(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> best, temp, globalBest;
        int swap, acceptanceProb = 20, acceptancefactor;
        float fitness, tempfitness, globalBestDistance, temperature = 1, e = 2.718;

        bool failed = true;

        //change alpha to change how the temperature is calculated
        float alpha = 0.9; //temperature is multiplied by this number every iteration

        for(unsigned int i = 0; i < vec.size(); i++)
        {
            best.push_back(i+1);
        }
        //First, generate a random solution
        std::random_shuffle(best.begin(), best.end());

        //ensures that the algorithm starts at Node 1
        for(unsigned int i = 0; i < best.size(); i++)
        {
            if(best[i] == 1)
            {
                swap = best[0];
                best[0] = 1;
                best[i] = swap;
            }
        }
        //Calculate its cost using some cost function you've defined
        fitness = getFitness(best, vec);
        globalBest = best;
        globalBestDistance = fitness;

        for(unsigned int i = 0; i < 100000; i++)
        {
            //Generate a random neighboring solution
            temp = generateNeighbor(best);
            //Calculate the new solution's cost
            tempfitness = getFitness(temp, vec);
            possiblePaths.push_back(temp);
            possibleDistances.push_back(tempfitness);
            //Compare them:
            //If cnew < cold: move to the new solution
            if(tempfitness < fitness)
            {
                best = temp;
                fitness = tempfitness;
            }
            else if(tempfitness > fitness)    //If cnew > cold: maybe move to the new solution
            {
                //acceptancefactor = rand() % 100 + 1;
                acceptancefactor = int(pow(e,(tempfitness - fitness)/temperature));
                if(acceptancefactor <= acceptanceProb)
                {
                    best = temp;
                    fitness = tempfitness;
                }
            }
            //Repeat steps 3-5 above until an acceptable solution is found or you reach some maximum number of iterations.
            if(fitness < globalBestDistance)
            {
                bestPath = best;
                globalBestDistance = fitness;
            }
            temperature *= alpha; //temperature is decreased every iteration
            if(globalBest == bestPath)
            {
                failed = false;
                break;
            }
        }
        if(failed)
        {
            bestPath = globalBest;
            bestDistance = globalBestDistance;
        }
        return "Simulated Annealing";
    }

    static std::string PSO(std::vector<Node> &vec, std::vector<int> &bestPath, float &bestDistance, std::vector<std::vector<int>> &possiblePaths, std::vector<float> &possibleDistances)
    {
        vector<vector<int>> routes, personalBests;
        vector<float> fitnessValues, personalBestDistances;
        vector<int> tempVec, velocities, globalBest;

        int swap;
        float temp, globalBestDistance = INT8_MAX;
        globalBestDistance = INT8_MAX;
        bool failed = true;

        /**
         * change these variables to alter PSO algorithm
         */
        int numParticles = 100;
        int maxIterations = 10000;
        int c1 = 2, c2 = 2;
        int maxVelocity = 100;

        //initializes the swarm
        for(unsigned int i = 0; i < numParticles; i++)
        {
            tempVec.clear();
            for(unsigned int i = 0; i < vec.size(); i++)
            {
                tempVec.push_back(i+1);
            }
            //First, generate a random solution
            std::random_shuffle(tempVec.begin(), tempVec.end());

            //ensures that the algorithm starts at Node 1
            for(unsigned int i = 0; i < tempVec.size(); i++)
            {
                if(tempVec[i] == 1)
                {
                    swap = tempVec[0];
                    tempVec[0] = 1;
                    tempVec[i] = swap;
                }
            }
            routes.push_back(tempVec);
            personalBests.push_back(tempVec);
            temp = getFitness(tempVec, vec);
            personalBestDistances.push_back(temp);
            fitnessValues.push_back(temp);
            velocities.push_back(0);
        }
        for(unsigned int i = 0; i < numParticles; i++)
        {
            if(fitnessValues[i] < globalBestDistance)
            {
                globalBest = routes[i];
                globalBestDistance = fitnessValues[i];
            }
        }

        int size = routes[0].size();

        for(unsigned int days = 0; days < maxIterations; days++)
        {
            //    For each particle
            for(unsigned int i = 0; i < numParticles; i++)
            {
            //        Calculate fitness value
                temp = getFitness(routes[i], vec);
            //        If the fitness value is better than the best fitness value (pBest) in history
                if(temp > globalBestDistance)
                {
            //            set current value as the new pBest
                    personalBestDistances[i] = temp;
                    personalBests[i] = routes[i];
                }
                possiblePaths.push_back(routes[i]);
                possibleDistances.push_back(temp);
            }
            //    Choose the particle with the best fitness value of all the particles as the gBest
            for(unsigned int i = 0; i < numParticles; i++)
            {
                if(fitnessValues[i] < globalBestDistance)
                {
                    globalBest = routes[i];
                    globalBestDistance = fitnessValues[i];
                }
            }
            //    For each particle
            for(unsigned int i = 0; i < numParticles; i++)
            {
                //formula to calculate velocities based on learning factor
                velocities[i] = velocities[i] + c1 *
                        (fitnessValues[i]-personalBestDistances[i]) + c2 *
                        (fitnessValues[i]-globalBestDistance);
                if(velocities[i] > maxVelocity)
                    velocities[i] = maxVelocity;
                else if(velocities[i] < maxVelocity * -1)
                    velocities[i] = maxVelocity * -1;
                if(routes[i] != globalBest)
                {
                    if(routes[i] != personalBests[i])
                        crossover(routes[i], personalBests[i], 1);

                    if(routes[i] != globalBest)
                    {
                        if(velocities[i] < 10)
                            crossover(routes[i], globalBest, 1);
                        else
                            crossover(routes[i], globalBest, velocities[i]/10);
                    }
                }
                else
                {
                    //if route is the closest route, introduce some random change
                    routes[i] = generateNeighbor(routes[i]);
                }

            }
            if(globalBest == bestPath)
            {
                failed = false;
                bestDistance = globalBestDistance;
                break;
            }
        }
        if(failed)
        {
            bestPath = globalBest;
            bestDistance = globalBestDistance;
        }
        return "Particle Swarm Optimization";
    }


    //these algorithms are from lab 3 and were used to compare timing and accuracy
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
