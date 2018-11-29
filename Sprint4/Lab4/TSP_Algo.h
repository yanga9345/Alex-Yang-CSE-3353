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

    static vector<int> newChromosome(vector<int> in, vector<int> IDs)
    {

        std::random_shuffle(IDs.begin(), IDs.end());
        in = IDs;
        return in;
    }

    static float getFitness(vector<int> IDs, vector<Node> vec)
    {
        float totalDistance = 0;
        for(unsigned int i = 0; i < IDs.size()-1; i++)
        {
            totalDistance += vec[IDs[i]].getDistance(vec[IDs[i+1]]);
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


    static void crossover(vector<int> &p1, vector<int> &p2)
    {
        int v1, temp1, temp2;
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

    static void mutation(vector<vector<int>> &population, int mutationChance)
    {
        //generates mutation rate between 1 and 100
        //generates two random numbers within the chromosome and swaps them for each thing in population
        int mutationRate, swap1, swap2, temp;
        for(unsigned int i = 0; i < population.size(); i++)
        {
            mutationRate = rand() % 100 + 1;
            if(mutationRate <= mutationChance)
            {
                swap1 = rand() % population[i].size();
                while(true)
                {
                    swap2 = rand() % population[i].size();
                    if(swap1 != swap2)
                        break;
                }
                temp = population[i][swap1];
                population[i][swap1] = population[i][swap2];
                population[i][swap2] = temp;
                cout << "";
            }
        }
    }

    static std::string GeneticAlgorithm(vector<Node> &vec, vector<int> &bestPath, float &bestDistance,  vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> IDs;
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            IDs.push_back(i);
        }

        vector<vector<int>> population;

        vector<int> chromosome1;
        vector<int> chromosome2;
        vector<int> chromosome3;
        vector<int> chromosome4;
        vector<int> chromosome5;
        vector<int> chromosome6;
        vector<int> chromosome7;
        vector<int> chromosome8;
        vector<int> chromosome9;
        vector<int> chromosome10;

        population.push_back(chromosome1);
        population.push_back(chromosome2);
        population.push_back(chromosome3);
        population.push_back(chromosome4);
        population.push_back(chromosome5);
        population.push_back(chromosome6);
        population.push_back(chromosome7);
        population.push_back(chromosome8);
        population.push_back(chromosome9);
        population.push_back(chromosome10);

        for(int i = 0; i < 10; i++)
        {
            population[i] = newChromosome(population[i], IDs);
        }

        vector<float> fitnessValues;

        for(unsigned int i = 0; i < 5; i++)
        {
            //determine fitness value of each chromosome (distance)
            fitnessValues.clear();
            for(unsigned int j = 0; j < 10; j++)
            {
                fitnessValues.push_back(getFitness(population[j], vec));
            }
            //determine which chromosomes go to the next generation (selection)
            selection(population, fitnessValues, 3);
            //create new genes in every generation to make it random
            repopulate(population, 3);
            //the ones that survive breed (crossover)
            for(unsigned int j = 0; j < population.size(); j+=2)
            {
                crossover(population[j], population[j+1]);
            }
            //determine mutation (determine if it happens and who it happens too)
            mutation(population, 30);

        }

        bestPath = population[0];
        bestDistance = fitnessValues[0];

        possiblePaths = population;
        possibleDistances = fitnessValues;

        return "Genetic Algorithm";
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
        if(n < 100)
            return (fac(n)/fac(n-k));
        else
            return 1000*n; //soft cap so program doesn't crash
    }

    //does the swapping in tabu search
    static void tabuSwap(vector<vector<int>> &population, vector<vector<int>> &tabuList, vector<int> &vec)
    {
        int swap1, swap2, temp;
        vector<int> tempVec, reverseVec;
        for(unsigned int i = 1; i < population.size()-1; i++)
        {

            if(tabuList.size() == 0)
            {
                while(true)
                {
                    swap1 = rand() % population[i].size();
                    swap2 = rand() % population[i].size();
                    if(swap1 != swap2)
                    {
                        tempVec.clear();
                        reverseVec.clear();
                        tempVec.push_back(swap1);
                        tempVec.push_back(swap2);
                        reverseVec.push_back(swap2);
                        reverseVec.push_back(swap1);
                        tabuList.push_back(tempVec);
                        tabuList.push_back(reverseVec);
                        break;
                    }
                }
                temp = population[i][swap1];
                population[i][swap1] = population[i][swap2];
                population[i][swap2] = temp;
            }
            else if (tabuList.size() < perm(vec.size(), 2)) //permutation perm(vec.size(), 2)
            {
                while(true)
                {
                    swap1 = rand() % population[i].size();
                    swap2 = rand() % population[i].size();
                    if(swap1 != swap2)
                    {
                        tempVec.clear();
                        reverseVec.clear();
                        tempVec.push_back(swap1);
                        tempVec.push_back(swap2);
                        reverseVec.push_back(swap2);
                        reverseVec.push_back(swap1);
                        if(!contains(tabuList, tempVec))
                        {
                            tabuList.push_back(tempVec);
                            tabuList.push_back(reverseVec);
                            break;
                        }
                    }
                }
                temp = population[i][swap1];
                population[i][swap1] = population[i][swap2];
                population[i][swap2] = temp;
            }
        }
    }

    //tabu
    static std::string Tabu(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
    {
        vector<int> tempVec;
        bestDistance = INT8_MAX;

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

        vector<vector<int>> population;
        vector<vector<int>> tabuList;
        vector<float> fitnessValues;

        //do this all 5 times

        //create greedy path

        //construct a path starting with node 1
        tempVec.push_back(IDs[0]);
        float shortestDistance = INT8_MAX;
        int closestNode = 0;
        int nodesLeft = IDs.size() - 1;
        while(nodesLeft > 0)
        {
            shortestDistance = INT8_MAX;
            for(int j = 0; j < IDs.size(); j++)
            {
                if(!contains(tempVec, j))
                {
                    if(matrix[tempVec[tempVec.size()-1]][j] < shortestDistance)
                    {
                        shortestDistance = matrix[tempVec[tempVec.size()-1]][j];
                        closestNode = j;
                    }
                }
            }
            tempVec.push_back(closestNode);
            nodesLeft--;
        }
        //find the shortest path from the previous node to current node
        //do this on a loop

        for(unsigned int i = 0; i < 5; i++)
        {
            population.clear();
            tabuList.clear();
            fitnessValues.clear();
            //create a neighbourhood based off the initial state
            population.push_back(tempVec);
            repopulate(population, 1);
            //clone it a lot and then mutate the clones (swap two nodes)
            //then put swapped nodes in a tabu list
            //go to next clone and swap two more nodes but check if they are on list
            tabuSwap(population, tabuList, IDs);
            //after ur tabu list is done, compares all the neighbors to the initial state

            for(unsigned int j = 0; j < population.size(); j++)
            {
                fitnessValues.push_back(getFitness(population[j], vec));
            }

            bestDistance = INT8_MAX;
            for(unsigned int i = 0; i < population.size(); i++)
            {
                if(fitnessValues[i] < bestDistance)
                {
                    bestDistance = fitnessValues[i];
                    bestPath = population[i];
                }
            }
            tempVec = bestPath;
        }
        return "Tabu";
    }
};

#endif // TSP_ALGO_H
