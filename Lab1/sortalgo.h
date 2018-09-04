#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>
#include <iostream>
#include "algorithm.h"
#include "tree.cpp"

using namespace std;

class SortAlgo
{
private:

public:
    static vector<void(*)(std::vector<int>&)> algorithms;
    SortAlgo();
    /*
    SortAlgo(vector<int> &dat, int sortType)
    {
        if (sortType == 0)
        {
            Bubble(dat);
        }
        else if(sortType == 1)
        {
            Insertion(dat);
        }
        else if(sortType == 2)
        {
            Merge(dat);
        }
        else
        {
            cout << "Error. " << endl;
        }
    }
    */

    template<typename T>
    void BinaryTree(vector<T> &data);
    template<typename T>
    void BinaryTreeSort(vector<T> &data, int index);

    template<typename T>
    static void Bubble(vector<T> &data);

    template<typename T>
    static void Insertion(vector<T> &data);

    template<typename T>
    static void Merge(vector<T> &data);
};

#endif // SORTALGO_H
