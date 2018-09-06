#ifndef SORT_H
#define SORT_H
#include "sortalgo.h"
#include "algorithm.h"
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

class Sort: public Algorithm
{
private:
    //void(*activeAlgo)(vector<int>&) = NULL;
    string(*activeAlgo)(vector<int>&) = NULL;
    //vector<void(*)(vector<int>&)> algorithms;
    vector<string(*)(vector<int>&)> algorithms;
    double runTime;
    string sortName, filename;
    //vector<int> intData;
public:
    int currentIndex;
    Sort();
    vector<int> intData;
    void Load(char*);
    void Select(int);
    void Execute();
    void Display();
    void Stats();
    void Save();
};

#endif // SORT_H
