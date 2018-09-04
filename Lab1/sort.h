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
    void(*activeAlgo)(vector<int>&) = NULL;
    vector<void(*)(vector<int>&)> algorithms;
    //vector<int> intData;
public:
    Sort();
    vector<int> intData;
    //void Load(vector<int> &dat);
    void Load(char*);
    void Select(int id);
    void Execute();
    void Display();
    void Stats();
    void Save();

};

#endif // SORT_H
