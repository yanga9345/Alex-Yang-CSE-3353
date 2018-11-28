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

//    //brute force algorithm
//    static string Brute_Force(vector<Node> &vec, vector<int> &bestPath, float &bestDistance, vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
//    {
//        vector<int> tempVec;
//        float totalDistance;

//        vector<int> IDs; //integer representation of my graph

//        //sets IDs to the IDs of each node of my graph
//        for(unsigned int i = 0; i < vec.size(); i++)
//        {
//            IDs.push_back(vec[i].getID() - 1);
//        }

//        //calculates the best path using brute force techniques
//        do
//        {
//            totalDistance = 0;
//            for(unsigned int i = 1; i < IDs.size(); i++)
//            {
//                totalDistance += vec[IDs[i-1]].getDistance(vec[IDs[i]]);
//            }
//            totalDistance += vec[0].getDistance(vec[vec.size()-1]);

//            if(totalDistance < bestDistance)
//            {
//                bestDistance = totalDistance;
//                bestPath.clear();
//                for(unsigned int j = 0; j < IDs.size(); j++)
//                {
//                    bestPath.push_back(IDs[j] + 1);
//                }
//            }

//            tempVec.clear();
//            for(unsigned int i = 0; i < vec.size(); i++)
//            {
//                tempVec.push_back(vec[IDs[i]].getID());
//            }
//            possiblePaths.push_back(tempVec);
//            possibleDistances.push_back(totalDistance);

//        } while(std::next_permutation(IDs.begin() + 1, IDs.end()));

//        return "Brute Force";
//    }


//    //dynamic programming
//    static string Dynamic_Programming(vector<Node> &vec, vector<int> &bestPath, float &bestDistance,  vector<vector<int>> &possiblePaths, vector<float> &possibleDistances)
//    {
//        vector<int> tempVec;
//        bestDistance = INT8_MAX;
//        float totalDistance;

//        //sets up an adjacency matrix
//        float** matrix = new float*[vec.size()];
//        for(unsigned int i = 0; i < vec.size(); i++)
//        {
//            matrix[i] = new float[vec.size()];
//        }

//        //loads up the values of the matrix with the distances between the i and j nodes
//        for(unsigned int i = 0; i < vec.size(); i++)
//        {
//            for(unsigned int j = 0; j < vec.size(); j++)
//            {
//                matrix[i][j] = vec[i].getDistance(vec[j]);
//            }
//        }

//        //vector of ints representing the ids of all the nodes
//        vector<int> IDs;
//        for(unsigned int i = 0; i < vec.size(); i++)
//        {
//            IDs.push_back(i);
//        }


//        do
//        {
//            totalDistance = 0;

//            for(unsigned int i = 1; i < IDs.size(); i++)
//            {
//                totalDistance += matrix[IDs[i-1]][IDs[i]];
//            }

//            totalDistance += matrix[0][IDs.size()-1];

//            if(totalDistance < bestDistance)
//            {
//                bestDistance = totalDistance;
//                bestPath.clear();
//                for(unsigned int i = 0; i < vec.size(); i++)
//                {
//                    bestPath.push_back(vec[IDs[i]].getID());
//                }
//            }

//            tempVec.clear();
//            for(unsigned int i = 0; i < vec.size(); i++)
//            {
//                tempVec.push_back(vec[IDs[i]].getID());
//            }
//            possiblePaths.push_back(tempVec);
//            possibleDistances.push_back(totalDistance);

//        } while(std::next_permutation(IDs.begin() + 1, IDs.end()));

//        return "Dynamic Programming";
//    }

    static vector<int> newChromosome(vector<int> in, vector<int> IDs)
    {

        std::random_shuffle(IDs.begin(), IDs.end());
        in = IDs;
        return in;
    }

    static float getFitness(vector<int> IDs, vector<Node> vec)
    {
        float totalDistance = 0;
        for(unsigned int i = 1; i < IDs.size(); i++)
        {
            totalDistance += vec[IDs[i-1]].getDistance(vec[IDs[i]]);
        }
        totalDistance += vec[0].getDistance(vec[vec.size()-1]);
        return totalDistance;
    }

    //selects the top populations based on fitness values
    static void selection(vector<vector<int>> &population, vector<float> &fitnessValues, int limit)
    {
        float key;
        vector<int> popKey;
        int i, j, size = fitnessValues.size(), popSize = population.size();
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
            population.erase(population.end());
            fitnessValues.erase(fitnessValues.end());
        }

        for(int i = 0; i < limit; i++)
        {
            cout << "Top " << limit << " Fitness Values: " << endl;
            cout << i+1 << " -> " << fitnessValues[i] << endl;
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
    static void repopulate(vector<vector<int>> &population)
    {
        int counter = 0;
        int popSize = population.size();
        for(int i = 0; i < 10 - popSize; i++)
        {
            population.push_back(population[counter]);
            if(counter == 2)
                counter = 0;
            counter++;
        }
    }

    static void mutation(vector<vector<int>> &population)
    {
        //generates mutation rate between 1 and 100
        //generates two random numbers within the chromosome and swaps them for each thing in population
        int mutationRate = rand() % 100 + 1;
        int swap1, swap2;
        if(mutationRate <= 30)
        {

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
            //the ones that survive breed (crossover)
            repopulate(population);
            for(unsigned int j = 0; j < population.size(); j+=2)
            {
                crossover(population[j], population[j+1]);
            }
            //determine mutation (determine if it happens and who it happens too)
            //create new genes in every generation to make it random

        }
        cout << "lol" << endl;

        return "Genetic Algorithm";
    }



    //tabu
    //what it do:
    //make matrix and shit
    //do this all 5 times
    //create greedy path
        //construct a path starting with node 1
        //find the shortest path from the previous node to current node
        //do this on a loop
    //create a neighbourhood based off the initial state
    //clone it a lot and then mutate the clones (swap two nodes)
    //then put swapped nodes in a tabu list
    //go to next clone and swap two more nodes but check if they are on list and if they are then just don't
    //after ur tabu list is done, compares all the neighbors to the initial state


};

#endif // TSP_ALGO_H