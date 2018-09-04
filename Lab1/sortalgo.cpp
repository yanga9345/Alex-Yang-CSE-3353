#include "sortalgo.h"

SortAlgo::SortAlgo()
{

}

template<typename T>
void SortAlgo::Bubble(vector<T> &data)
{

}

template<typename T>
void SortAlgo::Insertion(vector<T> &data)
{

}

template<typename T>
void SortAlgo::Merge(vector<T> &data)
{

}


template<typename T>
void SortAlgo::BinaryTree(vector<T> &data)
{
    SortAlgo::BinaryTreeSort(data, data.size());
}

template<typename T>
void SortAlgo::BinaryTreeSort(vector<T> &data, int index)
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

