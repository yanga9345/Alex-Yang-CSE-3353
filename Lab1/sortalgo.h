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
    void BinaryTree(vector<T> &data)
    {
        SortAlgo::BinaryTreeSort(data, data.size());
    }

    template<typename T>
    void BinaryTreeSort(vector<T> &data, int index)
    {
        struct Tree::Node * root = 0;
        root = Tree::InsertNode(root, data[0]);

        for(int i = 1; i < index; i++)
        {
            Tree::InsertNode(root, data[i]);
        }


        int i = 0;
        Tree::CopySortedTree(root, data, i);

    }

    //templated Bubble Sort Function
    template<typename T>
    static void Bubble(vector<T> &data)
    {
        T i, j, temp;
        int size = data.size();
        for (i = 0; i < size-1; i++)
        {
            for (j = 0; j < size-i-1; j++)
            {
                if (data[j] > data[j+1])
                {
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
    }

    template<typename T>
    static void Insertion(vector<T> &data)
    {

    }

    template<typename T>
    static void Merge(vector<T> &data)
    {

    }
};

#endif // SORTALGO_H
