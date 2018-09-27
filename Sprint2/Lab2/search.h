#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "searchalgo.h"
#include "graph.h"
#include "adjacencylist.h"
#include "dlinkedlist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <algorithm>

//header file for Sort Class
//inherits from Algorithm base class
class Search: public Algorithm
{
private:
    //function pointer of a function that takes in a vector of ints and returns a string (name of the type of sort [Bubble, Insertion, Merge])
    std::string(*activeAlgo)(DLinkedList<Source>, int, int) = NULL;
    //vector of function pointers described above
    std::vector<std::string(*)(DLinkedList<Source>, int, int)> algorithms;
    //time it takes to run a sort represented by a double
    double runTime;
    //strings for the name of the type of sort and the name of the file that is currently loaded
    string sortName, filename;
public:
    int currentIndex;
    Search();
    int source, destination;
    vector<int> intData; //vector of ints read from file
    Graph graph;
    DLinkedList<Source> sources;

    void Load(char*); //loads data file into Search
    void Load(char **);
    void Select(int); //selects the sorting method
    void Execute(); //executes the selected method
    void Display(); //prints the sorted vector
    void Stats(); //displays the file, sorting method used, and time it took to run
    void Save(); //outputs sorted vectors to text files
};

#endif // SORT_H
