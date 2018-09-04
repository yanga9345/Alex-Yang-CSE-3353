#ifndef SORT_H
#define SORT_H
#include "sortalgo.h"
#include "algorithm.h"

class Sort: public Algorithm
{
private:
    SortAlgo activeAlgo;
    vector<SortAlgo> algorithms;
    vector<int> intData;
public:
    Sort();
    void Exe();
    void Select(int id);
    void Load(vector<int> &dat);
};

#endif // SORT_H
