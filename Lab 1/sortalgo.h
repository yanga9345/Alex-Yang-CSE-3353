#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>
#include "algorithm.h"
#include "tree.cpp"

using namespace std;

class SortAlgo
{
private:

public:
    SortAlgo();
    SortAlgo(vector<int> &);

    template<typename T>
    void BinaryTree(vector<T> &data);
    template<typename T>
    void BinaryTreeSort(vector<T> &data, int index);

    template<typename T>
    void Bubble(vector<T> &data);
    template<typename T>
    void BubbleSort(vector<T> &data, int index);

    template<typename T>
    void Insertion(vector<T> &data);
    template<typename T>
    void InsertionSort(vector<T> &data, int index);

    template<typename T>
    void Merge(vector<T> &data);
    template<typename T>
    void MergeSort(vector<T> &data, int index);
};

#endif // SORTALGO_H
