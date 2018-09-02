#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>
#include "tree.cpp"

using namespace std;

class SortAlgo
{
public:
    template<typename T>
    void BinaryTree(vector<T> &data);
    template<typename T>
    void BinaryTreeSort(vector<T> &data, int index);
};

#endif // SORTALGO_H
