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

    //selects the top populations based on fitness values
    static void selection(vector<vector<int>> &population, vector<float> &fitnessValues, int limit)
    {
        float key;
        vector<int> popKey;
        int i, j, size = fitnessValues.size();
        for (i = 1; i < size; i++)
        {
            key = fitnessValues[i];
            popKey = population[i];
            j = i-1;

            while (j >= 0 && fitnessValues[j] > key)
            {
                fitnessValues[j+1] = fitnessValues[j];
                population[j+1] = population[j];
                j = j-1;
            }
            fitnessValues[j+1] = key;
            population[j+1] = popKey;
        }

        for(int i = 0; i < 10-limit; i++)
        {
            population.pop_back();
            fitnessValues.pop_back();
        }
    }


    static void crossover(vector<int> &p1, vector<int> &p2, int crossRate)
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
                    if(p2[j] == temp1)
                    {
                        p2[j] = temp2;
                    }
                }
            }
        }
    }

    //makes new babies
    static void repopulate(vector<vector<int>> &population, int limit)
    {
        int counter = 0;
        int popSize = population.size();
        vector<int> temp;
        for(int i = 0; i < 10 - popSize; i++)
        {
            temp = population[counter];
            population.push_back(temp);
            if(counter == limit-1)
                counter = 0;
            counter++;
        }
    }

    //checks if a vector contains an element
    template <typename t>
    static bool contains(vector<t> vec, t id)
    {
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == id)
                return true;
        }
        return false;
    }

    //calculates the factorial of an int
    static int fac(int n)
    {
        int total = n;
        while(n > 2)
        {
            n--;
            total *= n;
        }
        return total;
    }

    //calculates the permutation of two ints
    static int perm(int n, int k)
    {
        if(n < 35)
            return (fac(n)/fac(n-k));
        else
            return (fac(35)/fac(35-k)); //soft cap so program doesn't crash
            //return 1000*n;
    }

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

    static std::string SA(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> best, temp;
        int swap, acceptanceProb = 20, acceptancefactor;
        double fitness, tempfitness, temperature = 1, e = 2.718;

        //change alpha to change how the temperature is calculated
        double alpha = 0.90; //temperature is multiplied by this number every iteration

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
        bestPath = best;
        bestDistance = fitness;

        for(unsigned int i = 0; i < vec.size() * 1000; i++)
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
            if(fitness < bestDistance)
            {
                bestPath = best;
                bestDistance = fitness;
            }
            temperature *= alpha; //temperature is decreased every iteration
        }
        return "Simulated Annealing";
    }

    static std::string PSO(std::vector<Node> &vec, std::vector<int> &bestPath, float &bestDistance, std::vector<std::vector<int>> &possiblePaths, std::vector<float> &possibleDistances)
    {
        vector<vector<int>> routes, personalBests;
        vector<double> fitnessValues, personalBestDistances;
        vector<int> tempVec;
        vector<vector<int>> velocities;
        //vector<double> velocities;

        int swap, c1 = 2, c2 = 2;
        double temp;


//        //allows the particles to follow the PSO algorithm
//        for(unsigned int day = 0; day < 10; day++)
//        {
//            for(int i = 0; i < size; i++)
//            {
//                //if route is the closest route, introduce some random change
//                if(routes[i] == bestPath)
//                {
//                    routes[i] = generateNeighbor(routes[i]);
//                }
//                //if route is not the closest route, change the
//                //  route to be more similar to the global best
//                //  then make it more similar to the local best
//                else
//                {
//                    //moves the route one node closer to its personalbest and to the globalbest route
//                    if(routes[i] != personalBests[i])
//                    {
//                        for(unsigned int j = 0; j < routes[i].size(); j++)
//                        {
//                            if(routes[i][j] != personalBests[i][j])
//                            {
//                                routes[i][j] = personalBests[i][j];
//                                break;
//                            }
//                        }
//                        if(routes[i] != bestPath)
//                        {
//                            for(unsigned int j = 0; j < routes[i].size(); j++)
//                            {
//                                if(routes[i][j] != bestPath[i][j])
//                                {
//                                    routes[i][j] = bestPath[i][j];
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                }
//                possiblePaths.push_back(routes[i]);
//                temp = getFitness(routes[i], vec);
//                if(temp < bestDistance)
//                {
//                    bestPath = routes[i];
//                    bestDistance = temp;
//                }
//                if(temp < personalBestDistances[i])
//                {
//                    personalBestDistances[i] = temp;
//                    personalBests[i] = routes[i];
//                }
//            }
//        }

        bestDistance = INT8_MAX;

        int numParticles = 3;
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
            for(unsigned int j = 0; j < routes[i].size(); j++)
                velocities[i].push_back(0);
        }

        int size = routes.size();

        //    For each particle
        for(unsigned int i = 0; i < routes.size(); i++)
        {
        //        Calculate fitness value
            temp = getFitness(routes[i], vec);
        //        If the fitness value is better than the best fitness value (pBest) in history
            if(temp > bestDistance)
            {
        //            set current value as the new pBest
                personalBestDistances[i] = temp;
                personalBests[i] = routes[i];
            }
            possiblePaths.push_back(routes[i]);
            possibleDistances.push_back(temp);
        }
        //    Choose the particle with the best fitness value of all the particles as the gBest
        for(unsigned int i = 0; i < routes.size(); i++)
        {
            if(fitnessValues[i] < bestDistance)
            {
                bestPath = routes[i];
                bestDistance = fitnessValues[i];
            }
        }
        //    For each particle
        for(unsigned int i = 0; i < routes.size(); i++)
        {
            for(unsigned int j = 0; j < velocities[i].size(); j++)
            {
            //       Calculate particle velocity according equation (a)
                velocities[i][j] = velocities[i][j] + c1 * rand() *
                        (personalBestDistances[i] - fitnessValues[i]) + c2 * rand() *
                        (bestDistance - fitnessValues[i]);
            //       Update particle position according equation (b)
                routes[i][j] += velocities[i][j];
            }
        }
        return "Particle Swarm Optimization";
    }
};

#endif // TSP_ALGO_H
