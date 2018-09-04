#ifndef SORT_H
#define SORT_H
#include "sortalgo.h"
#include "algorithm.h"
#include <fstream>
#include <vector>

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
    void Exe();
    void Display();
    void Stats();
    void Save();

};

#endif // SORT_H
