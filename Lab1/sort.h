#ifndef SORT_H
#define SORT_H
#include "sortalgo.h"
#include "algorithm.h"
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

//header file for Sort Class
//inherits from Algorithm base class
class Sort: public Algorithm
{
private:
    //function pointer of a function that takes in a vector of ints and returns a string (name of the type of sort [Bubble, Insertion, Merge])
    string(*activeAlgo)(vector<int>&) = NULL;
    //vector of function pointers described above
    vector<string(*)(vector<int>&)> algorithms;
    //time it takes to run a sort represented by a double
    double runTime;
    //strings for the name of the type of sort and the name of the file that is currently loaded
    string sortName, filename;
public:
    int currentIndex;
    Sort();
    vector<int> intData; //vector of ints read from file
    void Load(char*); //loads data file into Sort
    void Select(int); //selects the sorting method (Bubble, Insertion, Merge)
    void Execute(); //executes the selected method
    void Display(); //prints the sorted vector
    void Stats(); //displays the file, sorting method used, and time it took to run
    void Save(); //outputs sorted vectors to text files
};

#endif // SORT_H
