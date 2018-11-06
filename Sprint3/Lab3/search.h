#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "searchalgo.h"
#include "node.h"
#include "filehandler.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>

//header file for Sort Class
//inherits from Algorithm base class
class Search: public Algorithm
{
private:
    //function pointer of a function that takes in a vector of ints and returns a string (name of the type of algorithm [Brute Force, Dynamic Programming])
    std::string(*activeAlgo)(vector<Node> &, vector<int> &, float &, vector<vector<int>> &, vector<float> &) = NULL;
    //vector of function pointers described above
    std::vector<std::string(*)(vector<Node> &, vector<int> &, float &, vector<vector<int>> &, vector<float> &)> algorithms;
    //time it takes to run an algorithm represented by a double
    double runTime;
    vector<int> bestPath;
    vector<vector<int>> possiblePaths;
    vector<float> possibleDistances;
    float bestDistance;
    //strings for the name of the type of algorithm and the name of the file that is currently loaded
    string algoName, filename;
    FileHandler f;
public:
    int currentIndex;
    Search();
    int source, destination;
    vector<int> intData; //vector of ints read from file
    vector<Node> vec;

//    void Load(char*); //loads data file into Search
//    void Load(char **);
    void Load();
    void Load(int);
    void Select(int); //selects the sorting method
    void Execute(); //executes the selected method
    void Display(); //prints the sorted vector
    void Stats(); //displays the file, sorting method used, and time it took to run
    void Save(); //outputs sorted vectors to text files
};

#endif // SORT_H
